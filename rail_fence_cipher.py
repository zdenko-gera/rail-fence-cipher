raw_text = ''
rail_key = 2

raw_text = input('Add meg a kodolni kivant szoveget: ')
rail_key = int(input('Add meg a rail key-t: (default: 2)'))

# print(raw_text)
# print(rail_key)

grid_width = len(raw_text)
grid_height = rail_key

grid = [['#' for x in range(grid_width)] for y in range(grid_height)]

j = 0
growing_index = True

for i in range(grid_width):
    grid[j][i] = raw_text[i]

    if growing_index and j < (rail_key - 1):
        j += 1
        continue
    elif growing_index and j == (rail_key - 1):
        growing_index = False
        j -= 1
        continue

    if not growing_index and j > 0:
        j -= 1
        continue
    elif not growing_index and j == 0:
        growing_index = True
        j += 1
        continue

cipher = ''

for k in range(grid_height):
    for i in range(grid_width):
        if grid[k][i] != '#':
            cipher += grid[k][i]
        #print(grid[k][i], end=' ')
    #print()

print(cipher)