# Problem Set 4A
# Name: <your name here>
# Collaborators:
# Time Spent: x:xx

def get_permutations(sequence):
    '''
    Enumerate all permutations of a given string

    sequence (string): an arbitrary string to permute. Assume that it is a
    non-empty string.  

    You MUST use recursion for this part. Non-recursive solutions will not be
    accepted.

    Returns: a list of all permutations of sequence

    Example:
    >>> get_permutations('abc')
    ['abc', 'acb', 'bac', 'bca', 'cab', 'cba']

    Note: depending on your implementation, you may return the permutations in
    a different order than what is listed here.
    '''

    if len(sequence) == 1:
        return [sequence]
    else:
        first_letter = sequence[0]
        permutation = get_permutations(sequence[1:])
        length = len(permutation[0])

        change_permutation = permutation[:]
        for string in permutation:
            for index in range(length+1):
                if index == 0:
                    change_permutation += [first_letter + string]
                    continue
                if index == length:
                    change_permutation += [string + first_letter]
                    break
                change_permutation += [string[:index] + first_letter + string[index:]]
            change_permutation.remove(string)

        return list({}.fromkeys(change_permutation).keys())


if __name__ == '__main__':
#    #EXAMPLE
#    example_input = 'abc'
#    print('Input:', example_input)
#    print('Expected Output:', ['abc', 'acb', 'bac', 'bca', 'cab', 'cba'])
#    print('Actual Output:', get_permutations(example_input))
    
#    # Put three example test cases here (for your sanity, limit your inputs
#    to be three characters or fewer as you will have n! permutations for a 
#    sequence of length n)

    # test case 1
    example_input = 'abc'
    print('Input:', example_input)
    print('Expected Output:', ['abc', 'acb', 'bac', 'bca', 'cab', 'cba'])
    print('Actual Output:', get_permutations(example_input))

    # test case 2
    example_input2 = 'see'
    print('Input:', example_input2)
    print('Expected Output:', ['see', 'ese', 'ees'])
    print('Actual Output:', get_permutations(example_input2))

    # test case 3
    example_input3 = 'eee'
    print('Input:', example_input3)
    print('Expected Output:', ['eee'])
    print('Actual Output:', get_permutations(example_input3))
    
