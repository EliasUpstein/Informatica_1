double convertTemp(double temp, char dest)
{
    if (dest == 'c')
        temp = (temp - 32) * 5/9;
    else if (dest == 'f')
        temp = (temp * 9/5) + 32;
    else
        temp = temp;

    return temp;
}