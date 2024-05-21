import pygame
import time

pygame.init()
pygame.font.init()

# SETTINGS
width = 400
height = 400
screen = pygame.display.set_mode((height, width))
pygame.display.set_caption("Tic-Tac-Toe")
font = pygame.font.SysFont(None, 24)
symb = pygame.font.SysFont(None, 72)

offset = 30
line_breadth = 15
rgb = (25, 25, 25)
running = True

pygame.display.update()

maxX, minO = 'x', 'o'
Bsize = 3
INF = 1e9


def full(matrix):
    for i in range(Bsize):
        for j in range(Bsize):
            if matrix[i][j] == '-':
                return False
    return True


def eval(matrix):
    for i in range(Bsize):
        if matrix[i][0] == matrix[i][1] == matrix[i][2]:
            if matrix[i][0] == maxX:
                return 1
            elif matrix[i][0] == minO:
                return -1

    for i in range(Bsize):
        if matrix[0][i] == matrix[1][i] == matrix[2][i]:
            if matrix[0][i] == maxX:
                return 1
            elif matrix[0][i] == minO:
                return -1

    if matrix[0][0] == matrix[1][1] == matrix[2][2]:
        if matrix[0][0] == maxX:
            return 1
        elif matrix[0][0] == minO:
            return -1

    if matrix[2][0] == matrix[1][1] == matrix[0][2]:
        if matrix[2][0] == maxX:
            return 1
        elif matrix[2][0] == minO:
            return -1
    return 0


def minimax(board1, depth, isMaxX):
    points = eval(board)
    board1 = board
    if points == 1:
        return points

    if points == -1:
        return points

    if full(board):
        return 0

    if isMaxX:
        sc = -INF
        for i in range(Bsize):
            for j in range(Bsize):
                # try an available move and find all the combinations
                if board[i][j] == '-':
                    board[i][j] = maxX
                    sc = max(minimax(board, depth + 1, False), sc)
                    board[i][j] = '-'
        return sc
    else:
        sc = INF
        for i in range(Bsize):
            for j in range(Bsize):
                if board[i][j] == '-':
                    board[i][j] = minO
                    sc = min(minimax(board, depth + 1, True), sc)
                    board[i][j] = '-'
        return sc


def show(matrix):
    print("+------------------------------------+")
    for i in range(Bsize):
        for j in range(Bsize):
            print(matrix[i][j], end=" ")
        print("")
    print("+------------------------------------+")
    return


def put(table):
    for i in range(len(table)):
        for j in range(len(table)):
            if table[i][j] == 'x':
                txt = symb.render('x', False, (0,0,0))
                screen.blit(txt, ((63 + j*120), (63 + 120*i)))

            elif table[i][j] == 'o':
                txt = symb.render('o', False, (0,0,0))
                screen.blit(txt, ((63 + j*120), (63 + 120*i)))

    pygame.display.update()


def cn():
    screen.fill((250, 250, 250))
    text = font.render('>>> insert your coordinates: ', False, (0, 0, 0))
    screen.blit(text, (0, 0))
    pygame.draw.line(screen, rgb, (width / 3, offset),
                     (width / 3, height - offset), 7)

    pygame.draw.line(screen, rgb, (width / 3 * 2, offset),
                     (width / 3 * 2, height - offset), 7)

    # drawing horizontal lines
    pygame.draw.line(screen, rgb, (offset, height / 3),
                     (width - offset, height / 3), 7)
    pygame.draw.line(screen, rgb, (offset, height / 3 * 2),
                     (width - offset, height / 3 * 2), 7)
    pygame.display.update()


def searchPerfect(board, player):
    while running:
        cn()
        put(board)
        coordinates = [-1, -1]
        soFar = INF
        if player:
            a = 0
            while a < 2:
                event = pygame.event.wait()
                keys = pygame.key.get_pressed()
                if keys[pygame.K_0]:
                    coordinates[a]=0
                    a+=1
                    time.sleep(0.2)
                if keys[pygame.K_1]:
                    coordinates[a]=1
                    a+=1
                    time.sleep(0.2)
                if keys[pygame.K_2]:
                    coordinates[a]=2
                    a+=1
                    time.sleep(0.2)
            board[coordinates[0]][coordinates[1]] = maxX
            
        elif not player:
            for i in range(Bsize):
                for j in range(Bsize):
                    if board[i][j] == '-':
                        board[i][j] = minO
                        value = minimax(board, 0, True)
                        board[i][j] = '-'
                        if value < soFar:
                            coordinates[0] = i
                            coordinates[1] = j
                            soFar = value

            board[coordinates[0]][coordinates[1]] = minO

            
        show(board)
        put(board)
        ans = eval(board)


        if ans == 1:
            screen.fill((250, 250, 250))
            end = font.render('>>> You won.', False, (0,0,0))
            screen.blit(end, (0, 0))
            pygame.display.update()
            time.sleep(3)
            return
        elif ans == -1:
            time.sleep(3)
            screen.fill((250, 250, 250))
            end = font.render('>>> You lose.', False, (0,0,0))
            screen.blit(end, (0, 0))
            pygame.display.update()
            time.sleep(3)
            return
        
        elif full(board):
            time.sleep(3)
            screen.fill((250, 250, 250))
            end = font.render('>>> Stalemate', False, (0,0,0))
            screen.blit(end, (0, 0))
            pygame.display.update()
            time.sleep(3)
            return
        player = (not player)


# driver code
board = [
    ['-', '-', '-'],
    ['-', '-', '-'],
    ['-', '-', '-']
]
player = True

searchPerfect(board, player)
