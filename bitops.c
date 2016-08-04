#include <Python.h>

long i;
int shift_bits;
int num_bits;
char *hex_str;

static PyObject *
right_shift(PyObject *self, PyObject *args)
{
    PyArg_ParseTuple(args, "ll", &i, &shift_bits);
    return Py_BuildValue("l", i >> shift_bits);
}

static PyObject *
left_shift(PyObject *self, PyObject *args)
{
    PyArg_ParseTuple(args, "ll", &i, &shift_bits);
    return Py_BuildValue("l", i << shift_bits);
}

static PyObject *
get_value_of_first_n_bits(PyObject *self, PyObject *args)
{
    PyArg_ParseTuple(args, "ll", &i, &num_bits);
    return Py_BuildValue("l", i & ((1 << num_bits) - 1));
}

static PyObject *
hex_to_int(PyObject *self, PyObject *args)
{
    PyArg_ParseTuple(args, "s", &hex_str);
    return Py_BuildValue("l", strtol(hex_str, NULL, 16));
}

static PyMethodDef bitopsMethods[] =
{
     {"right_shift", right_shift, METH_VARARGS, "Shift Right."},
     {"left_shift", left_shift, METH_VARARGS, "Shift Left."},
     {"get_value_of_first_n_bits", get_value_of_first_n_bits, METH_VARARGS, "Mask out all but the first n bits."},
     {"hex_to_int", hex_to_int, METH_VARARGS, "Calculate int value of hex string."},
     {NULL, NULL, 0, NULL}
};

void initbitops(void)
{
    // Init module.
    (void) Py_InitModule("bitops", bitopsMethods);
}