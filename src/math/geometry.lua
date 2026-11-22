---@class math.geometry
local M = class('math.geometry')
local mat4 = require('math.mat4')
local vec3 = require('math.vec3')
local sqrt = math.sqrt
local insert = table.insert

function M:ctor()
    ---@type math.vec3[]
    self._verts = {}
    self._edges = {}
    self._faces = {}
    self._pts = {}
end

function M:_getEdge(index)
    local e = self._edges[index]
    return { self._verts[e[1]], self._verts[e[2]] }
end
function M:_getEdges()
    local out = {}
    for i = 1, #self._edges do
        insert(out, self:_getEdge(i))
    end
    return out
end

---@param translate math.vec3
---@param scale math.vec3|number
---@param quaternion math.quaternion
function M:setTransform(translate, scale, quaternion)
    self:setTransformMat(mat4:createTransform(translate, scale, quaternion))
end

---@param transform_mat math.mat4
function M:setTransformMat(transform_mat)
    self._tf = transform_mat
end

function M:getVertCount()
    return #self._verts
end
function M:getEdgeCount()
    return #self._edges
end

function M:getVerts(out)
    out = out or {}
    if self._tf then
        for _, v in ipairs(self._verts) do
            insert(out, self._tf:transformVector(v))
        end
    else
        for _, v in ipairs(self._verts) do
            insert(out, v:clone())
        end
    end
    return out
end

function M:getEdges(out)
    out = out or {}
    local verts = self:getVerts()
    for _, v in ipairs(self._edges) do
        insert(out, { verts[v[1]], verts[v[2]] })
    end
    return out
end

function M.Tetrahedron()
    local ret = M()
    ret._verts = {
        vec3(sqrt(8 / 9), 0, -1 / 3),
        vec3(-sqrt(2 / 9), sqrt(2 / 3), -1 / 3),
        vec3(-sqrt(2 / 9), -sqrt(2 / 3), -1 / 3),
        vec3(0, 0, 1),
    }
    ret._edges = {
        { 1, 2 }, { 2, 3 }, { 3, 4 },
        { 1, 3 }, { 2, 4 }, { 1, 4 },
    }
    return ret
end

function M.Cube()
    local ret = M()
    local a = 1 / sqrt(3)
    local b = -a
    ret._verts = {
        vec3(a, a, a), vec3(a, a, b), vec3(a, b, b), vec3(a, b, a),
        vec3(b, a, a), vec3(b, a, b), vec3(b, b, b), vec3(b, b, a),
    }
    ret._edges = {
        { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 1 },
        { 5, 6 }, { 6, 7 }, { 7, 8 }, { 8, 5 },
        { 1, 5 }, { 2, 6 }, { 3, 7 }, { 4, 8 },
    }
    return ret
end

function M.Octahedron()
    local ret = M()
    local a = 1 / sqrt(2)
    local b = -a
    ret._verts = {
        vec3(a, 0, 0), vec3(0, a, 0), vec3(0, 0, a),
        vec3(b, 0, 0), vec3(0, b, 0), vec3(0, 0, b),
    }
    ret._edges = {
        { 1, 2 }, { 2, 3 }, { 1, 3 },
        { 4, 5 }, { 5, 6 }, { 4, 6 },
        { 3, 4 }, { 3, 5 },
        { 1, 6 }, { 2, 6 },
        { 1, 5 }, { 2, 4 },
    }
    return ret
end

function M.Dodecahedron()
    local ret = M()
    local phi = (sqrt(5) + 1) / 2
    local a = phi / sqrt(3)
    local b = 1 / phi / sqrt(3)
    local c = 1 / sqrt(3)
    ret._verts = {
        vec3(c, c, c), vec3(c, c, -c), vec3(c, -c, -c), vec3(c, -c, c),
        vec3(-c, c, c), vec3(-c, c, -c), vec3(-c, -c, -c), vec3(-c, -c, c),
        vec3(0, a, b), vec3(0, a, -b), vec3(0, -a, -b), vec3(0, -a, b),
        vec3(b, 0, a), vec3(b, 0, -a), vec3(-b, 0, -a), vec3(-b, 0, a),
        vec3(a, b, 0), vec3(a, -b, 0), vec3(-a, -b, 0), vec3(-a, b, 0),
    }
    ret._edges = {
        { 1, 9 }, { 1, 13 }, { 1, 17 },
        { 2, 10 }, { 2, 14 }, { 2, 17 },
        { 3, 11 }, { 3, 14 }, { 3, 18 },
        { 4, 12 }, { 4, 13 }, { 4, 18 },
        { 5, 9 }, { 5, 16 }, { 5, 20 },
        { 6, 10 }, { 6, 15 }, { 6, 20 },
        { 7, 11 }, { 7, 15 }, { 7, 19 },
        { 8, 12 }, { 8, 16 }, { 8, 19 },
        { 9, 10 },
        { 11, 12 },
        { 13, 16 },
        { 14, 15 },
        { 17, 18 },
        { 19, 20 },
    }
    return ret
end

function M.Icosahedron()
    local ret = M()
    local phi = (sqrt(5) + 1) / 2
    local a = 1 / sqrt(phi + 2)
    local b = a * phi
    ret._verts = {
        vec3(0, a, b), vec3(0, a, -b), vec3(0, -a, -b), vec3(0, -a, b),
        vec3(b, 0, a), vec3(b, 0, -a), vec3(-b, 0, -a), vec3(-b, 0, a),
        vec3(a, b, 0), vec3(a, -b, 0), vec3(-a, -b, 0), vec3(-a, b, 0),
    }
    ret._edges = {
        { 1, 4 }, { 1, 5 }, { 1, 8 }, { 1, 9 }, { 1, 12 },
        { 2, 3 }, { 2, 6 }, { 2, 7 }, { 2, 9 }, { 2, 12 },
        { 3, 6 }, { 3, 7 }, { 3, 10 }, { 3, 11 },
        { 4, 5 }, { 4, 8 }, { 4, 10 }, { 4, 11 },
        { 5, 6 }, { 5, 9 }, { 5, 10 },
        { 6, 9 }, { 6, 10 },
        { 7, 8 }, { 7, 11 }, { 7, 12 },
        { 8, 11 }, { 8, 12 },
        { 9, 12 },
        { 10, 11 },
    }
    return ret
end

return M
