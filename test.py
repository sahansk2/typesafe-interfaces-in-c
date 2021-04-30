import ctypes

class SQUARE(ctypes.Structure):
    _fields_ = [
        ("length", ctypes.c_int),
        ("id", ctypes.c_int)
    ]
import pathlib

if __name__ == '__main__':
    libname = pathlib.Path().absolute() / 'build' / 'libshape.so'
    mylib = ctypes.cdll.LoadLibrary(libname)
    print(mylib.Square_area(ctypes.byref(SQUARE(length=12))))
