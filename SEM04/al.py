def diferencia(arr):
    mayor = arr[0]
    menor = arr[0]

    for x in arr:
        if x > mayor:
            mayor = x
        if x < menor:
            menor = x

    return mayor - menor

a = [6, 2, 9, 1, 7]
print("Diferencia:", diferencia(a.copy()))










