#!/bin/bash
#SBATCH --job-name=    # Job name
#SBATCH --output=output.log       # Output file
#SBATCH --error=error.log         # Error file
#SBATCH --partition=your_partition   # Specify the partition/queue
#SBATCH --nodes=1                 # Number of nodes
#SBATCH --ntasks=1                # Number of tasks (processes)
#SBATCH --cpus-per-task=1         # Number of CPU cores per task
#SBATCH --mem=2G                  # Memory per node
#SBATCH --time=01:00:00           # Maximum execution time (HH:MM:SS)

# Load any necessary modules or activate the virtual environment if needed
# module load your_module
# source activate your_virtual_env

# Change directory to your working directory (where main.py is located)
cd /path/to/your/src_directory

# Run the Python command
python src/main.py --config_file config/TP/FlowChain/CIF_separate_cond_v_trajectron/eth.yml --mode test

# Deactivate the virtual environment if you activated one
# source deactivate
