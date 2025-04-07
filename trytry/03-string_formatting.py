from string import Template

FIRST = "Sebastian"
LAST = "Witowski"
AGE = 33


# # def old_style():
# #     return "Hello %s %s (%i)" % (FIRST, LAST, AGE)



def new_style():
    return "Hello {} {} ({})".format(FIRST, LAST, AGE)


# # def f_strings():
# #     return f"Hello {FIRST} {LAST} ({AGE})"

# # #python -m timeit -s "from string_formatting import f_strings" "f_strings()"
print( new_style())
# # #python -m timeit -s "from string_formatting import old_style" "old_style()"
