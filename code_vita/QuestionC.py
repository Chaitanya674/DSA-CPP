def generate_permutations(characters, length, prefix=''):
    if length == 0:
        yield prefix
    else:
        for i, char in enumerate(characters):
            yield from generate_permutations(characters[:i] + characters[i + 1:], length - 1, prefix + char)

def solve(rank, length):
    characters = ''.join(map(chr, range(ord('a'), ord('a') + 26)))
    for permutation in generate_permutations(characters, length):
        if rank == 1:
            return permutation
        rank -= 1

rank = int(input())
length = int(input())
print(solve(rank, length))