--

local int = math.floor
local sin = math.sin
local cos = math.cos
--local asin = math.asin
local acos = math.acos
local pow = math.pow
local exp = math.exp
local sqrt = math.sqrt
local pi = math.pi
local _e = math.exp(1)
local log = math.log
local insert = table.insert

local NV_MAGICCONST = 4 * exp(-0.5) / sqrt(2.0)
local TWOPI = 2.0 * pi
local LOG4 = log(4.0)
local SG_MAGICCONST = 1.0 + log(4.5)
--local BPF = 53        -- Number of bits in a float
--local RECIP_BPF = pow(2, -BPF)

---@class math.Random
local M = {}

-------------------- integer methods  -------------------

--- Choose a random item from range(start, stop[, step]).
--- It does not include the endpoint.
---@param start number
---@param stop number
---@param step number
---@return number
function M:randrange(start, stop, step)
    local istart = int(start)
    if istart ~= start then
        error("non-integer arg 1 for randrange()")
    end
    if not stop then
        if istart > 0 then
            return self:_randbelow(istart)
        end
        error("empty range for randrange()")
    end
    -- stop argument supplied.
    local istop = int(stop)
    if istop ~= stop then
        error("non-integer stop for randrange()")
    end
    local width = istop - istart
    step = step or 1
    if step == 1 and width > 0 then
        return istart + self:_randbelow(width)
    end
    if step == 1 then
        error(string.format(
                "empty range for randrange() (%d, %d, %d)",
                istart, istop, width))
    end
    -- Non-unit step argument supplied.
    local istep = int(step)
    if istep ~= step then
        error("non-integer step for randrange()")
    end
    local n
    if istep > 0 then
        n = int((width + istep - 1) / istep)
    elseif istep < 0 then
        n = int((width + istep + 1) / istep)
    else
        error("zero step for randrange()")
    end
    if n <= 0 then
        error("empty range for randrange()")
    end
    return istart + istep * self:_randbelow(n)
end

---Return random integer in range [a, b], including both end points.
---@param a number
---@param b number
---@return number
function M:randint(a, b)
    return self:randrange(a, b + 1)
end

local _maxsize = math.pow(2, 53)

---Return a random int in the range [0, n)
---@param n number
---@return number
function M:_randbelow(n)
    if n <= 0 then
        error('n <= 0')
    end
    local random = self.random
    if n >= _maxsize then
        return int(random(self) * n)
    end
    local rem = _maxsize % n
    local limit = (_maxsize - rem) / _maxsize
    local r = random(self)
    while r >= limit do
        r = random(self)
    end
    return int(r * _maxsize) % n
end

-------------------- sequence methods  -------------------

---Choose a random element from a non-empty sequence.
function M:choice(seq)
    local len = #seq
    if len == 0 then
        error("Cannot choose from an empty sequence")
    end
    return seq[self:_randbelow(len) + 1]
end

--- Shuffle list x in place, and return None.
---
--- Optional argument random is a 0-argument function returning a
--- random float in [0.0, 1.0); if it is the default None, the
--- standard random.random will be used.
function M:shuffle(x, random)
    local len = #x
    if not random then
        for i = len, 2, -1 do
            local j = self:_randbelow(i) + 1
            x[i], x[j] = x[j], x[i]
        end
    else
        for i = len, 2, -1 do
            local j = int(random() * i) + 1
            x[i], x[j] = x[j], x[i]
        end
    end
end

--- Chooses k unique random elements from a population sequence or set.
---
--- Returns a new list containing elements from the population while
--- leaving the original population unchanged.  The resulting list is
--- in selection order so that all sub-slices will also be valid random
--- samples.  This allows raffle winners (the sample) to be partitioned
--- into grand prize and second place winners (the subslices).
---
--- Members of the population need not be hashable or unique.  If the
--- population contains repeats, then each occurrence is a possible
--- selection in the sample.
---@param population table
---@param k number
---@return table
function M:sample(population, k)
    local n = #population
    if k < 0 or k > n then
        error("Sample larger than population")
    end
    local result = {}
    local mark = {}
    for i = 1, k do
        local j = self:_randbelow(i) + 1
        insert(result, population[mark[j] or j])
        mark[j] = mark[k - i + 1] or n - i + 1
    end
    return result
end

-------------------- real-valued distributions  -------------------

-------------------- uniform distribution -------------------


--- Get a random number in the range [a, b) or [a, b] depending on rounding.
---@param a number
---@param b number
---@return number
function M:uniform(a, b)
    return a + (b - a) * self:random()
end

-------------------- triangular --------------------

--- Triangular distribution.
---
--- Continuous distribution bounded by given lower and upper limits,
--- and having a given mode value in-between.
---
--- http://en.wikipedia.org/wiki/Triangular_distribution
---@param low number
---@param high number
---@param mode number
---@return number
function M:triangular(low, high, mode)
    low = low or 0
    high = high or 1
    local c = 0.5
    if mode then
        local div = high - low
        if div == 0 then
            return low
        else
            c = (mode - low) / div
        end
    end
    local u = self:random()
    if u > c then
        u = 1 - u
        c = 1 - c
        low, high = high, low
    end
    return low + (high - low) * pow(u * c, 0.5)
end

-------------------- normal distribution --------------------

--- Normal distribution.
--- mu is the mean, and sigma is the standard deviation.
---@param mu number
---@param sigma number
---@return number
function M:normalvariate(mu, sigma)
    local z, zz, u1, u2
    while true do
        u1 = self:random()
        u2 = 1 - self:random()
        z = NV_MAGICCONST * (u1 - 0.5) / u2
        zz = z * z / 4
        if zz <= -log(u2) then
            break
        end
    end
    return mu + z * sigma
end

-------------------- lognormal distribution --------------------

--- Log normal distribution.
---
--- If you take the natural logarithm of this distribution, you'll get a
--- normal distribution with mean mu and standard deviation sigma.
--- mu can have any value, and sigma must be greater than zero.
---@param mu number
---@param sigma number
---@return number
function M:lognormvariate(mu, sigma)
    return exp(self:normalvariate(mu, sigma))
end

-------------------- exponential distribution --------------------


---Exponential distribution.
---
--- lambd is 1.0 divided by the desired mean.  It should be
--- nonzero.  (The parameter would be called "lambda", but that is
--- a reserved word in Python.)  Returned values range from 0 to
--- positive infinity if lambd is positive, and from negative
--- infinity to 0 if lambd is negative.
---@param lambd number
---@return number
function M:expovariate(lambd)
    return -log(1 - self:random()) / lambd
end

-------------------- von Mises distribution --------------------

--- Circular data distribution.
---
--- mu is the mean angle, expressed in radians between 0 and 2*pi, and
--- kappa is the concentration parameter, which must be greater than or
--- equal to zero.  If kappa is equal to zero, this distribution reduces
--- to a uniform random angle over the range 0 to 2*pi.
---@param mu number
---@param kappa number
---@return number
function M:vonmisesvariate(mu, kappa)
    if kappa <= 1e-6 then
        return TWOPI * self:random()
    end
    local s = 0.5 / kappa
    local r = s + sqrt(1 + s * s)
    local z, d, u1, u2
    while true do
        u1 = self:random()
        z = cos(pi * u1)
        d = z / (r + z)
        u1 = self:random()
        if u2 < 1 - d * d or u2 <= (1 - d) * exp(d) then
            break
        end
    end
    local q = 1 / r
    local f = (q + z) / (1 + q * z)
    local u3 = self:random()
    if u3 > 0.5 then
        return (mu + acos(f)) % TWOPI
    else
        return (mu - acos(f)) % TWOPI
    end
end

-------------------- gamma distribution --------------------


--- Gamma distribution.  Not the gamma function!
---
--- Conditions on the parameters are alpha > 0 and beta > 0.
---
--- The probability distribution function is:
---
---             x ** (alpha - 1) * math.exp(-x / beta)
---   pdf(x) =  --------------------------------------
---               math.gamma(alpha) * beta ** alpha
---@param alpha number
---@param beta number
---@return number
function M:gammavariate(alpha, beta)
    if alpha <= 0 or beta <= 0 then
        error("gammavariate: alpha and beta must be > 0.0")
    end
    if alpha > 1 then
        local ainv = sqrt(2 * alpha - 1)
        local bbb = alpha - LOG4
        local ccc = alpha + ainv
        local u1, u2, v, x, z, r
        while true do
            u1 = self:random()
            while 1e-7 > u1 or u1 > 1 - 1e-7 do
                u1 = self:random()
            end
            u2 = 1 - self:random()
            v = log(u1 / (1.0 - u1)) / ainv
            x = alpha * exp(v)
            z = u1 * u1 * u2
            r = bbb + ccc * v - x
            if r + SG_MAGICCONST - 4.5 * z >= 0.0 or r >= log(z) then
                return x * beta
            end
        end
    elseif alpha == 1 then
        local u = self:random()
        while u < 1e-7 do
            u = self:random()
        end
        return -log(u) * beta
    else
        local u, u1, b, p, x
        while true do
            u = self:random()
            b = (_e + alpha) / _e
            p = b * u
            if p <= 1 then
                x = pow(p, 1 / alpha)
            else
                x = -log((b - p) / alpha)
            end
            u1 = self:random()
            if p > 1 then
                if u1 <= pow(x, alpha - 1) then
                    break
                end
            elseif u1 <= exp(-x) then
                break
            end
        end
        return x * beta
    end
end

-------------------- Gauss (faster alternative) --------------------

--- Gaussian distribution.
---
--- mu is the mean, and sigma is the standard deviation.  This is
--- slightly faster than the normalvariate() function.
---@param mu number
---@param sigma number
---@return number
function M:gauss(mu, sigma)
    local z = self.gauss_next
    self.gauss_next = nil
    if not z then
        local x2pi = self:random() * TWOPI
        local g2rad = sqrt(-2 * log(1 - self:random()))
        z = cos(x2pi) * g2rad
        self.gauss_next = sin(x2pi) * g2rad
    end
    return mu + z * sigma
end

-------------------- beta --------------------

--- Beta distribution.
---
--- Conditions on the parameters are alpha > 0 and beta > 0.
--- Returned values range between 0 and 1.
---@param alpha number
---@param beta number
---@return number
function M:betavariate(alpha, beta)
    local y = self:gammavariate(alpha, 1)
    if y == 0 then
        return 0
    else
        return y / (y + self:gammavariate(beta, 1))
    end
end

-------------------- Pareto --------------------

--- Pareto distribution.  alpha is the shape parameter.
---@param alpha number
---@return number
function M:paretovariate(alpha)
    local u = 1 - self:random()
    return 1 / pow(u, 1 / alpha)
end

-------------------- Weibull --------------------


--- Weibull distribution.
---
--- alpha is the scale parameter and beta is the shape parameter.
---@param alpha number
---@param beta number
---@return number
function M:weibullvariate(alpha, beta)
    local u = 1 - self:random()
    return alpha * pow(-log(u), 1 / beta)
end

function M:random()
    if self._random_g then
        return self._random_g()
    else
        return math.random()
    end
end

function M:seed(a)
    if self._random_s then
        self._random_s(a)
    else
        math.randomseed(a)
    end
    self.gauss_next = nil
end

function M:_set_random(generator, seeder)
    self._random_g = generator
    self._random_s = seeder
end

return M
