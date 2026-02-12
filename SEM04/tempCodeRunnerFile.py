def suma_pos_pares(arr):
    suma = 0
    for i in range(0, len(arr), 2):
        suma += arr[i]
    return suma

a = [5, 10, 15, 20, 25]
print("Suma posiciones pares:", suma_pos_pares(a.copy()))