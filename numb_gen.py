import random

def generate_random_numbers(filename: str, num_values: int, min_value: int, max_value: int):
    with open(filename, "w") as f:
        for _ in range(num_values):
            f.write(f"{random.randint(min_value, max_value)}\n")

    print(f"Generated {num_values} random numbers and saved to {filename}")

for i in range(1, 101):
    generate_random_numbers(f"generated_num/random_numbers_{i}.txt", 10000, 1, 100000)
