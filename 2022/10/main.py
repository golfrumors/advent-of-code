cycles_of_interest = [20, 60, 100, 140, 180, 220]
signal_strength_sum = 0
x = 1
cycle = 0

with open("D:\\source\\repos\\advent-of-code\\2022\\10\\input.txt") as f:
    # Read the instructions from the file.
    instructions = f.readlines()

# Open the file containing the instructions.


    # Initialize the X register to 1 and the cycle number to 0.

    # Initialize a list of cycles of interest and a variable to store the sum of the
    # signal strengths.

    # Execute the instructions one by one until we reach a cycle of interest.
while len(cycles_of_interest) > 0:
        # Move to the next instruction.
    cycle += 1

        # Get the current instruction and its operand (if any).
    instruction, *operand = instructions[cycle % len(instructions)].split()

        # Execute the instruction.
    if instruction == "noop":
        pass
    elif instruction == "addx":
        x += int(operand[0])

        # If we have reached a cycle of interest, compute the signal strength and
        # add it to the running total.
    if cycle == cycles_of_interest[0]:
        signal_strength_sum += cycle * x
        cycles_of_interest.pop(0)

    # Output the sum of the signal strengths.
print(signal_strength_sum)
