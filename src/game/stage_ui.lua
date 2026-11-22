---
--- stage_ui.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---


function ui.DrawScore()
    SetFontState('score3', '', Color(0xFFADADAD))
    local diff = string.match(stage.current_stage.name, "[%w_][%w_ ]*$")
    local diffimg = CheckRes('img', 'image:diff_' .. diff)
    if diffimg then
        Render('image:diff_' .. diff, 580, 448)
    else
        if diff == 'Easy' or diff == 'Normal' or diff == 'Hard' or diff == 'Lunatic' or diff == 'Extra' then
            Render('rank_' .. diff, 580, 448, 0.5, 0.5)
        else
            RenderText('score', diff, 580, 466, 0.5, 'center')
        end
    end
    --local line_x=525
    local line_x = 560
    local yy = 402
    Render('line_1', line_x, yy, 0, 1, 1)
    yy = yy - 32
    Render('line_2', line_x, yy, 0, 1, 1)
    yy = yy - 36
    Render('line_3', line_x, yy, 0, 1, 1)
    yy = yy - 48
    Render('line_4', line_x, yy, 0, 1, 1)
    yy = yy - 42
    Render('line_5', line_x, yy, 0, 1, 1)
    yy = yy - 23
    Render('line_6', line_x, yy, 0, 1, 1)
    yy = yy - 22
    Render('line_7', line_x, yy, 0, 1, 1)
    --local xx=428
    local xx = 512
    yy = 425
    Render('hint.hiscore', xx, yy, 0, 0.75)
    yy = yy - 32
    Render('hint.score', xx, yy, 0, 0.75)
    yy = yy - 32
    Render('hint.Pnumber', xx, yy, 0, 0.75)
    yy = yy - 48
    Render('hint.Bnumber', xx, yy, 0, 0.75)

    yy = 326
    Render('hint.Cnumber', xx + 80, yy, 0, 0.85, 0.85)
    Render('hint.Cnumber', xx + 80, yy - 48, 0, 0.85, 0.85)

    --RenderText('score','HiScore\nScore\nPlayer\nSpell\nGraze',432,424,0.5,'left')
    --xx=xx+77

    SetFontState('score3', '', Color(0xFFADADAD))
    RenderScore('score3', max(lstg.tmpvar.hiscore or 0, lstg.var.score), 636, 420, 0.43, 'right')

    SetFontState('score3', '', Color(0xFFFFFFFF))
    RenderScore('score3', lstg.var.score, 636, 388, 0.43, 'right')

    xx = 520
    yy = 344
    for i = 1, 8 do
        Render('hint.life', xx + 13 * i, yy, 0, 1, 1)
    end
    for i = 1, lstg.var.lifeleft do
        Render('hint.lifeleft', xx + 13 * i, yy, 0, 1, 1)
    end

    for i = 1, 8 do
        Render('hint.bomb', xx + 13 * i, yy - 48, 0, 1, 1)
    end
    for i = 1, lstg.var.bomb do
        Render('hint.bombleft', xx + 13 * i, yy - 48, 0, 1, 1)
    end
    local Lchip = lstg.var.chip
    if Lchip > 0 and Lchip < 5 then
        Render('lifechip' .. Lchip, xx + 13 * (lstg.var.lifeleft + 1), yy, 0, 1, 1)
    end
    local Bchip = lstg.var.bombchip
    if Bchip > 0 and Bchip < 5 then
        Render('bombchip' .. Bchip, xx + 13 * (lstg.var.bomb + 1), yy - 48, 0, 1, 1)
    end

    yy = 332
    xx = 608
    RenderText('score3', string.format('%d/5', lstg.var.chip), xx, yy, 0.35, 'left')
    RenderText('score3', string.format('%d/5', lstg.var.bombchip), xx, yy - 48, 0.35, 'left')
    --Render('hint.power',450,258,0,0.5)
    --Render('hint.point',452,240,0,0.5)
    --Render('hint.graze',466,222,0,0.5)
    SetFontState('score1', '', Color(0xFFCD6600))
    SetFontState('score2', '', Color(0xFF22D8DD))
    ---
    yy = 253
    xx = 512
    Render('hint.power', xx, yy, 0, 0.5, 0.5)
    Render('hint.point', xx, yy - 23, 0, 0.5, 0.5)
    Render('hint.graze', xx + 15, yy - 45, 0, 0.5, 0.5)

    xx = 636
    yy = yy + 9

    RenderText('score1', '', 0, 0)
    RenderText('score1', string.format('%d.    /4.',
            math.floor(lstg.var.power / 100)),
            xx - 16, yy, 0.4, 'right')

    RenderText('score1', string.format('      %d%d        00',
            math.floor((lstg.var.power % 100) / 10),
            math.floor(lstg.var.power % 10)),
            xx + 1, yy - 3.5, 0.3, 'right')

    local pointrate = lstg.var.pointrate
    local pointrate_str = string.format('%d,%d%d%d',
            math.floor(pointrate / 1000),
            math.floor(pointrate / 100) % 10,
            math.floor(pointrate / 10) % 10,
            math.floor(pointrate % 10))
    RenderText('score2', '', xx, yy - 23, 0.4, 'right')
    RenderText('score2', pointrate_str, xx, yy - 23, 0.4, 'right')

    SetFontState('score3', '', Color(0xFFADADAD))
    RenderText('score3', string.format('%d', lstg.var.graze), xx, yy - 45, 0.4, 'right')
end
