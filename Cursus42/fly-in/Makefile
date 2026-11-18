VENV = .venv
BIN = $(VENV)/bin
PIP = $(BIN)/pip
PYTHON = $(BIN)/python3
DEBUG = $(PYTHON) -m pdb

MAP = $(firstword $(filter-out requirements.txt, $(wildcard *.txt)))
MAIN = fly-in.py

FLAKE = $(BIN)/flake8 .
MYPY = $(BIN)/mypy . --warn-return-any --warn-unused-ignores --ignore-missing-imports --disallow-untyped-defs --check-untyped-defs
MYPY_STRICT = $(BIN)/mypy . --strict

INSTALLED = $(VENV)/.installed

all: run

$(PYTHON): 
	python3 -m venv $(VENV)
	$(PIP) install --upgrade pip

$(INSTALLED): $(PYTHON) requirements.txt
	$(PIP) install -r requirements.txt
	touch $(INSTALLED)

install: $(INSTALLED)

run: install
	$(PYTHON) $(MAIN) $(MAP)

debug: install
	$(DEBUG) $(MAIN) $(MAP)

lint: install
	$(FLAKE)
	$(MYPY)

lint-strict: install
	$(FLAKE)
	$(MYPY_STRICT) 

clean:
	rm -rf $(VENV)
	find . -type d \( -name "__pycache__" -o -name ".mypy_cache" \) -prune -exec rm -rf {} +

re: clean all

.PHONY: all run install lint lint-strict clean debug re