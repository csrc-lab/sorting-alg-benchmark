import os
import random
from itertools import chain

import matplotlib.pyplot as plt


def generate_random_distribution(size=1000, min_val=1, max_val=1000):
    """Generate a random distribution."""
    return [random.randint(min_val, max_val) for _ in range(size)]


def generate_sorted_distribution(size=1000):
    """Generate a sorted distribution, either ascending or descending."""
    return list(range(size))


def generate_slightly_scrambled(size=1000, scramble_percentage=5):
    """Generate a slightly scrambled distribution."""
    distribution = list(range(size))
    scramble_count = int(size * (scramble_percentage / 100))
    for _ in range(scramble_count):
        idx1 = random.randint(0, size - 1)
        idx2 = random.randint(0, size - 1)
        distribution[idx1], distribution[idx2] = distribution[idx2], distribution[idx1]
    return distribution


def generate_few_inversions(size=1000, inversion_count=20):
    """Generate a few inversions distribution."""
    distribution = list(range(size))
    for _ in range(inversion_count):
        idx = random.randint(0, size - 2)
        distribution[idx], distribution[idx +
                                        1] = distribution[idx + 1], distribution[idx]
    return distribution


def generate_sorted_blocks(size=1000, block_size=100):
    """Generate sorted blocks distribution."""
    distribution = []
    for _ in range(0, size, block_size):
        block = list(range(_, _ + block_size))
        distribution.append(block)
    random.shuffle(distribution)
    return list(chain.from_iterable(distribution))


def generate_single_big_swap(size=1000):
    """Generate single big swap distribution."""
    half_size = size // 2
    first_half = list(range(half_size))
    second_half = list(range(half_size, size))
    distribution = second_half + first_half
    return distribution


def generate_reversed_distribution(size=1000):
    """Generate a reversed distribution."""
    return list(range(size, 0, -1))


def generate_few_unique_distribution(size=1000, unique_values=10):
    """Generate a distribution with few unique values."""
    unique_elements = [random.randint(1, size) for _ in range(unique_values)]
    return [random.choice(unique_elements) for _ in range(size)]


def plot_distribution(distribution, title):
    """Plot a given distribution with a title."""
    plt.figure(figsize=(10, 4))
    plt.bar(range(len(distribution)), distribution)
    plt.title(title)
    plt.xlabel('Index')
    plt.ylabel('Value')
    plt.show()


def save_distribution(distribution, title, path):
    """Save a given distribution to a file."""
    # if the path contains directory, create it
    if "/" in path:
        directory = "/".join(path.split("/")[:-1])
        os.makedirs(directory, exist_ok=True)

    with open(path, "w") as f:
        f.write(" ".join(str(x) for x in distribution))


# Example usage
if __name__ == "__main__":
    sizes = [100, 1000, 10000, 100000, 1000000]
    for size in sizes:
        distributions = [
            ("random", generate_random_distribution(size)),
            ("sorted", generate_sorted_distribution(size)),
            ("scrambled", generate_slightly_scrambled(size, scramble_percentage=5)),
            ("sorted_blocks", generate_sorted_blocks(size, block_size=10)),
            ("single_big_swap", generate_single_big_swap(size)),
            ("reversed", generate_reversed_distribution(size)),
            ("few_unique", generate_few_unique_distribution(size, unique_values=5)),
        ]
        for title, dist in distributions:
            save_distribution(dist, title, f"{title}/{size}.txt")
