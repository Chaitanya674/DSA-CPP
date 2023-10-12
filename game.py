import random

# Define the Wumpus World grid size and create a grid
GRID_SIZE = 4
grid = [[' ' for _ in range(GRID_SIZE)] for _ in range(GRID_SIZE)]

# Define the location of the agent, gold, Wumpus, and pits
agent_location = (0, 0)
gold_location = (2, 3)
wumpus_location = (1, 1)
pit_locations = [(3, 0), (1, 2), (3, 3)]

# Initialize game state
game_over = False
has_gold = False

# Define the actions an agent can take
ACTIONS = ["MOVE_UP", "MOVE_DOWN", "MOVE_LEFT", "MOVE_RIGHT", "GRAB", "SHOOT"]

# Function to print the current state of the grid
def print_grid():
    for i in range(GRID_SIZE):
        for j in range(GRID_SIZE):
            if (i, j) == agent_location:
                print("*", end=" | ")  # Display agent with a star
            elif (i, j) == gold_location:
                print("G", end=" | ")  # Display gold
            elif (i, j) == wumpus_location:
                print("W", end=" | ")  # Display Wumpus
            elif (i, j) in pit_locations:
                print("P", end=" | ")  # Display pits
            else:
                print(" ", end=" | ")  # Empty cell
        print("\n" + "-" * (GRID_SIZE * 4 - 1))

# Main game loop
while not game_over:
    print_grid()

    # Get user input for action
    action = input("Enter action (e.g., MOVE_UP, GRAB, SHOOT): ").strip().upper()

    if action not in ACTIONS:
        print("Invalid action. Please enter a valid action.")
        continue

    # Perform the selected action
    if action.startswith("MOVE_"):
        new_x, new_y = agent_location

        if action == "MOVE_UP":
            new_x -= 1
        elif action == "MOVE_DOWN":
            new_x += 1
        elif action == "MOVE_LEFT":
            new_y -= 1
        elif action == "MOVE_RIGHT":
            new_y += 1

        if 0 <= new_x < GRID_SIZE and 0 <= new_y < GRID_SIZE:
            agent_location = (new_x, new_y)
        else:
            print("Invalid move. Agent hit the wall.")

    elif action == "GRAB":
        if agent_location == gold_location:
            has_gold = True
            grid[gold_location[0]][gold_location[1]] = ' '  # Remove gold from the grid
            print("Agent has grabbed the gold!")
        else:
            print("No gold to grab here.")

    elif action == "SHOOT":
        if wumpus_location == agent_location:
            print("Agent has shot the Wumpus! You win!")
            game_over = True
        else:
            print("No Wumpus to shoot here.")

    # Check for game-ending conditions
    if agent_location in pit_locations:
        print("Agent fell into a pit! Game over.")
        game_over = True
    elif agent_location == wumpus_location:
        print("Agent was eaten by the Wumpus! Game over.")
        game_over = True
    elif agent_location == gold_location and has_gold:
        print("Agent has climbed out of the cave with the gold! You win!")
        game_over = True

print("Game Over.")