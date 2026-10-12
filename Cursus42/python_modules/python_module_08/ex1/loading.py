#!/usr/bin/env python3

from importlib.metadata import version
import importlib

def check_missing_deps() -> bool:
    dependencies: list[str] = ["pandas", "numpy", "matplotlib"]
    missing: bool = False
    for dep in dependencies:
        try:
            importlib.import_module(dep)
        except ModuleNotFoundError:
            missing = True
            print("Missing dependency: {}".format(dep))
    return missing

def main() -> None:
    if check_missing_deps():
        print("Install missing dependencies with pip(1) or poetry(2):")
        print("1: Run 'pip install -r requirements.txt' and 'python loading.py'")
        print("2: Run 'poetry install', and 'poetry run python loading.py'")
        return
    print("\nLOADING STATUS: Loading programs...\n")
    print("Checking dependencies:")
    print("[OK] pandas", version("pandas"), "- Data manipulation ready")
    print("[OK] numpy", version("numpy"), "- Numerical computation ready")
    print("[OK] matplotlib", version("matplotlib"), "- Visualization ready")
    pd = importlib.import_module("pandas")
    np = importlib.import_module("numpy")
    plt = importlib.import_module("matplotlib.pyplot")
    x = np.random.rand(1000)
    y = np.random.rand(1000)
    data = pd.DataFrame({"x": x, "y": y})
    print("\nAnalyzing Matrix data...")
    plt.scatter(data["x"], data["y"])
    print("Processing 1000 data points...")
    print("Generating visualization...")
    plt.savefig('matrix_analysis.png')
    print("\nAnalysis complete!")
    print("Results saved to: matrix_analysis.png")

if __name__ == "__main__":
    main()