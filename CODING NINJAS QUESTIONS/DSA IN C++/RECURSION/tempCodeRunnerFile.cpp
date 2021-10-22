int count;
    if (n % 10 == 7 || n % 10 == 9)
        count = 4;
    else if (n % 10 == 0 || n % 10 == 1)
        count = 1;
    else
        count = 3