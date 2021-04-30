from ctypes import Structure, c_int, c_float, c_void_p, cdll, CFUNCTYPE, byref
import pathlib
import unittest

libname = pathlib.Path().absolute() / 'build' / 'libtest.so'
libtest = cdll.LoadLibrary(libname)


class TestAreas(unittest.TestCase):
    def test_square_area(self):
        self.assertEqual(1, libtest.test_square_area())

    def test_triangle_area(self):
        self.assertEqual(1, libtest.test_triangle_area())


if __name__ == '__main__':
    unittest.main()