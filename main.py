m = int(input('Введите кол-во строк: '))
n = int(input('Введите кол-во столбцов: '))

def print_board(board):
    print('  ', end='')
    for i in range(len(board[0])):
        print(i+1, end=' ')
    print()
    for i, el in enumerate(board):
        print(i+1, *el)

board = []
for i in range(m):
    mass1 = []
    for i in range(n):
        if i == 0: mass1.append('X')
        elif i == n-1: mass1.append('O')
        else: mass1.append('.')
    board.append(mass1)

print_board(board)
player = 1
while True:
    try:
        stopX = []
        stopO = []
        for i in board:
            if i[0] == 'X' and i[1] == 'O': stopX.append(True)
            else: stopX.append(False)
            if i[-1] == 'O' and i[-2] == 'X': stopO.append(True)
            else: stopO.append(False)
        if False not in stopX:
            print('Победил O')
            exit(0)
        if False not in stopO:
            print('Победил X')
            exit(0)
        print(f'Ход игрока {player}')
        if player == 1:
            row = int(input('Выберите X: '))-1
            cols = int(input('На какой столбец вы хотите походить: '))-1
            text = board[row]
            while cols == ''.join(text).find('X'):
                print('Ход не возможен')
                print_board(board)
                cols = int(input('На какой столбец вы хотите походить: '))-1
            if cols >= ''.join(text).find('O'): print('Ход не возможен')
            else:
                player = 2
                text.remove('X')
                text.insert(cols, 'X')
            print_board(board)
        elif player == 2:
            row = int(input('Выберите O: '))-1
            cols = int(input('На какой столбец вы хотите походить: '))-1
            text = board[row]
            while cols == ''.join(text).find('O'):
                print('Ход не возможен')
                print_board(board)
                cols = int(input('На какой столбец вы хотите походить: '))-1
            if cols <= ''.join(text).find('X'): print('Ход не возможен')
            else:
                player = 1
                text.remove('O')
                text.insert(cols, 'O')
            print_board(board)
    except IndexError:
        print('Ход не возможен')