from ctypes import Structure, c_int, c_float, c_void_p, cdll, CFUNCTYPE, byref
import pathlib
import unittest

SHAPE_AREA = CFUNCTYPE(c_float, c_void_p)

class ISHAPEAREAFUNCS(Structure):
    _fields_ = [
        ('area', SHAPE_AREA)
    ]

class ISHAPEAREA(Structure):
    _fields_ = [
        ('vself', c_void_p),
        ('funcs', ISHAPEAREAFUNCS)
    ]

class SQUARE(Structure):
    _fields_ = [
        ("length", c_int),
        ("id", c_int),
        ("ishapearea", ISHAPEAREA)
    ]

class TRIANGLE(Structure):
    _fields_ = [
        ("base", c_int),
        ("height", c_int),
        ("id", c_int),
        ("ishapearea", ISHAPEAREA)
    ]

libname = pathlib.Path().absolute() / 'build' / 'libshape.so'
libshapes = cdll.LoadLibrary(libname)
libshapes.Triangle_area.restype = c_float


class TestAreas(unittest.TestCase):
    def test_square_area(self):
        square = SQUARE(length=12)
        self.assertEqual(144, libshapes.Square_area(byref(square)))

    def test_triangle_area(self):
        triangle = TRIANGLE(base=2, height=1)
        self.assertEqual(1, libshapes.Triangle_area(byref(triangle)))


if __name__ == '__main__':
    unittest.main()
    pass