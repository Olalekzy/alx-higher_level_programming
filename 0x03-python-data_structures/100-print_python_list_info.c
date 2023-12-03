void print_python_list_info(PyObject *p) 
{
    Py_ssize_t size, i;
    PyObject *item;

    if (!PyList_Check(p)) 
    {
        fprintf(stderr, "Invalid Python List!\n");
        return;
    }

    size = PyList_Size(p);
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    for (i = 0; i < size; i++) 
    {
        item = PyList_GetItem(p, i);
        if (item != NULL) 
	{
            printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
        } else 
	{
            fprintf(stderr, "Failed to retrieve element %ld\n", i);
        }
    }
}
