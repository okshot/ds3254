import random

def generate_random_numbers(filename: str, num_values: int, min_value: int, max_value: int):
    with open(filename, "w") as f:
        for _ in range(num_values):
            f.write(f"{random.randint(min_value, max_value)}\n")

    print(f"Generated {num_values} random numbers and saved to {filename}")

for i in range(1, 11):
    generate_random_numbers(f"random_numbers_{i}.txt", 100000, 1, 100000)
