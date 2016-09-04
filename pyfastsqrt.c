#include <Python.h>
/*
A variant of the above routine is included below, which can be used to compute the reciprocal of the square root,
x^-1\2 instead, was written by Greg Walsh. The integer-shift approximation produced a relative error of less than 4%,
and the error dropped further to 0.15% with one iteration of Newton's method on the following line.[13] In computer
graphics it is a very efficient way to normalize a vector.

main article: https://en.wikipedia.org/wiki/Fast_inverse_square_root
*/


float inv_sqrt(float x)
{
    float xhalf = 0.5f*x;
    union
    {
        float x;
        int i;
    } u;
    u.x = x;
    u.i = 0x5f3759df - (u.i >> 1);
    /* The next line can be repeated any number of times to increase accuracy */
    u.x = u.x * (1.5f - xhalf * u.x * u.x);
    return u.x;
}

static PyObject *
pyfastsqrt_inv_sqrt(PyObject *self, PyObject *args)
{
    float x;
    if(!PyArg_ParseTuple(args, "f", &x))
        return(NULL);
    return PyLong_FromLong(inv_sqrt(x));
}

static PyMethodDef pyfastsqrt_methods[] = {
    { "inv_sqrt",  pyfastsqrt_inv_sqrt, METH_VARARGS, },
    { NULL, 0, 0, NULL }
};

static struct PyModuleDef pyfastsqrt_module =
{
    PyModuleDef_HEAD_INIT,
    "pyfastsqrt",       /* Имя модуля   */
    NULL,               /* документация по модулу, может быть NULL */
    -1,                 /* размер прединтерпредатора модуля или -1 если модуль содержит глобальные переменные */
    pyfastsqrt_methods
};

PyMODINIT_FUNC
PyInit_pyfastsqrt(void){
    return PyModule_Create(&pyfastsqrt_module);
}