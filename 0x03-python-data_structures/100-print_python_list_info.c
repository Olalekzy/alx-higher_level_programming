#include <stdlib.h>
#include <stdio.h>
#include <Python.h>

/**
 * print_python_list_info - function that prints basic info about Python lists
 * @p: pointer to a PyObject representing a Python list
 */
void print_python_list_info(PyObject *p)
{
    Py_ssize_t size, i;  // Use Py_ssize_t for Python's size type

    // Print the size of the list
    printf("[*] Size of the Python List = %ld\n", Py_SIZE(p));

    // Print the memory allocated for the list
    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    // Print info about each element in the list
    size = Py_SIZE(p);
    for (i = 0; i < size; i++)
    {
        PyObject *item = PyList_GetItem(p, i);
        if (item != NULL)
        {
            // Print the type name of each element
            printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
        }
        else
        {
            // Handle the case where getting the item fails
            fprintf(stderr, "Failed to retrieve element %ld\n", i);
        }
    }
}
