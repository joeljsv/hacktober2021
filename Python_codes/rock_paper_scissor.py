from random import randint

player = input('Rock(r),Paper(p),Scissor(s)?')
computer = randint(1, 3)
if computer == 1:
    computer = 'r'
elif computer == 2:
    computer = 'p'
else:
    computer = 's'
print(player, 'vs', computer)
if player == computer:
    print('Draw!!')
elif player == 's' and computer == 'p':
    print("Player Wins!!")
elif player == 'p' and computer == 's':
    print('Computer Wins!!')
elif player == 'p' and computer == 'r':
    print("Player Wins!!")
elif player == 'r' and computer == 'p':
    print('Computer Wins!!')
elif player == 'r' and computer == 's':
    print('Player Wins!!')
elif player == 's' and computer == 'r':
    print('Computer Wins!!')
