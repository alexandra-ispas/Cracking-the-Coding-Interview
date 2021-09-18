def is_unique(string):
    array = []
    for character in string:
        if character not in array:
            array.append(character)
        else:
            return False
    return True


def check_permutation(str1, str2):
    return sorted(str1) == sorted(str2)


def urlify(string, length):
    nr_of_spaces = 0
    characters = list(string)
    for idx in range(0, length):
        if characters[idx] == ' ':
            nr_of_spaces += 1

    i = 2 * nr_of_spaces + length - 1

    for idx in range(length - 1, 0, -1):
        if characters[idx] != ' ':
            characters[i] = characters[idx]
            i -= 1
        else:
            characters[i] = '0'
            characters[i - 1] = '2'
            characters[i - 2] = '%'
            i -= 3

    return "".join(characters)


def palindrome_permutation(string):
    hash_table = {}
    for character in string.lower():
        if character != ' ':
            try:
                hash_table[character] += 1
            except KeyError:
                hash_table[character] = 1

    ok = 0
    for counter in hash_table.values():
        if counter % 2 == 1:
            if ok == 0:
                ok = 1
            else:
                return False
    return True


def one_away(string1, string2):
    if string1 == string2:
        return True
    if abs(len(string1) - len(string2)) > 1:
        return False

    # replace
    if len(string1) == len(string2):
        diff = 0
        for idx in range(0, len(string1)):
            if string1[idx] != string2[idx]:
                diff += 1
            if diff > 1:
                return False
        return True
    else:
        if len(string1) > len(string2):
            length = len(string2)
            bigger = string1
            smaller = string2
        else:
            length = len(string1)
            bigger = string2
            smaller = string1

        for idx in range(0, length):
            if smaller[idx] != bigger[idx]:
                return smaller[idx:] == bigger[idx + 1:]

        return True


def string_compression(string):
    index1 = 0
    compressed_string = []
    while index1 < len(string) - 1:
        compressed_string.append(string[index1])
        counter = 1
        for index2 in range(index1 + 1, len(string)):
            if string[index2] == string[index1]:
                counter += 1
            if string[index2] != string[index1] or index2 == len(string) - 1:
                index1 = index2
                compressed_string.append(f'{counter}')
                break
    return "".join(compressed_string)


def matrix_printer(matrix, rows):
    for row in range(0, rows):
        print(matrix[row])


def rotate_matrix(matrix, n):
    for i in range(0, n // 2):
        for j in range(i, n - i - 1):
            aux = matrix[i][j]
            matrix[i][j] = matrix[j][n - i - 1]
            matrix[j][n - i - 1] = matrix[n - i - 1][n - j - 1]
            matrix[n - i - 1][n - j - 1] = matrix[n - j - 1][i]
            matrix[n - j - 1][i] = aux

    matrix_printer(matrix, n)


def zero_matrix(matrix, m, n):
    rows = []
    cols = []
    for i in range(0, m):
        for j in range(0, n):
            if matrix[i][j] == 0:
                rows.append(i)
                cols.append(j)

    for i in range(0, m):
        for j in range(0, n):
            if i in rows or j in cols:
                matrix[i][j] = 0

    matrix_printer(matrix, m)


def is_substring(substring, string):
    substring_length = len(substring)
    string_length = len(string)

    for i in range(0, string_length - substring_length + 1):
        for j in range(0, substring_length):
            if string[i + j] != substring[j]:
                break
            if j + 1 == substring_length:
                return True
    return False


def string_rotation(s1, s2):
    return is_substring(s2, s1 + s1)
