from ctypes import cdll
import pathlib
import unittest


class CTestWrapper(unittest.TestCase):
    def setUp(self):
        libname = pathlib.Path() / 'build' / 'libtest.so'
        self.libtest = cdll.LoadLibrary(libname)

    def test_square_area(self):
        self.assertEqual(1, self.libtest.test_square_area())

    def test_triangle_area(self):
        self.assertEqual(1, self.libtest.test_triangle_area())


if __name__ == '__main__':
    unittest.main()