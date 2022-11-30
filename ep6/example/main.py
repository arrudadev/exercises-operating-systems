import ctypes

biblioteca = ctypes.CDLL("libtriplo.so")
biblioteca.triplo.argtypes = [ctypes.c_int]
biblioteca.triplo.restype = ctypes.c_int
valor = biblioteca.triplo(10)

print(valor)
