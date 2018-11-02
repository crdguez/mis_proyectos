
# Probando parse_latex o como pasar expresiones LaTeX a SymPy

Importamos la función *parse_latex*:


```python
from sympy.parsing.latex import parse_latex
```

Solo nos queda pasar un *string* con la expresión LaTeX para que la función devuelva la expresión en código entendible por Sympy. **NOTA:** *El string conviene pasarlo en formato "raw string literal"*

**Ejemplo:**


```python
parse_latex(r'\frac{x^2}{\sqrt{y}}')
```




    x**2/sqrt(y)




```python
#Código para exportar el notebook a markdown (Opcional)
!jupyter nbconvert --to=markdown Probando_parse_latex.ipynb
```

    [NbConvertApp] Converting notebook Probando_parse_latex.ipynb to markdown
    [NbConvertApp] Writing 707 bytes to Probando_parse_latex.md

