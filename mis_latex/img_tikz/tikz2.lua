local function tikz2image(src, filetype, outfile)
    local tmp = os.tmpname()
    local tmpdir = string.match(tmp, "^(.*[\\/])") or "."
    local f = io.open(tmp .. ".tex", 'w')
    f:write("\\documentclass{standalone}\n\\usepackage{pgf,tikz,pgfplots}\n\\pgfplotsset{compat=1.15}\n\\usepackage{mathrsfs}\n\\usetikzlibrary{arrows}\n\\newcommand{\\degre}{\\ensuremath{^\\circ}}\n\\begin{document}\n\\definecolor{wrwrwr}{rgb}{0.3803921568627451,0.3803921568627451,0.3803921568627451}\n\\definecolor{rvwvcq}{rgb}{0.08235294117647059,0.396078431372549,0.7529411764705882}\\ %")
    -- f:write("\\documentclass{standalone}\n\\usepackage{tikz}\n\\begin{document}\n")
    -- f:write("\\documentclass{article}\n\\usepackage{tikz}\n\\begin{document}\n")
    f:write(src)
    f:write("\n\\end{document}\n")
    f:close()
    os.execute("pdflatex -output-directory " .. tmpdir  .. " " .. tmp)
    if filetype == 'pdf' then
        os.rename(tmp .. ".pdf", outfile)
    else
        os.execute("convert " .. tmp .. ".pdf " .. outfile)
    end
    -- os.remove(tmp .. ".tex")
    os.remove(tmp .. ".pdf")
    os.remove(tmp .. ".log")
    os.remove(tmp .. ".aux")
end

extension_for = {
    html = 'png',
    html4 = 'png',
    html5 = 'png',
    latex = 'pdf',
    beamer = 'pdf' }

local function file_exists(name)
    local f = io.open(name, 'r')
    if f ~= nil then
        io.close(f)
        return true
    else
        return false
    end
end

function RawBlock(el)
    local filetype = extension_for[FORMAT] or "png"
    local fname = pandoc.sha1(el.text) .. "." .. filetype
    if not file_exists(fname) then
        tikz2image(el.text, filetype, fname)
    end
    return pandoc.Para({pandoc.Image({}, fname)})
end
