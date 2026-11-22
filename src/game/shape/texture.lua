--


--
local M = {}

function M.setCircle(obj, tex, nCol, nRow, r, texRect,color)
    local tri = lstg.Triangles:createCircle(
            nCol, nRow, r, texRect)
    if color then
        tri:setAllVertexColor(color)
    end
    tex:setTriangles(tri)
    obj.img = tex
end

function M.setSectorRing(obj, tex, nCol, nRow, rOuter, rInner, angle, texRect,color)
    local tri = lstg.Triangles:createSector(
            nCol, nRow, rOuter, rInner, angle, texRect)
    if color then
        tri:setAllVertexColor(color)
    end
    tex:setTriangles(tri)
    obj.img = tex
end

return M

