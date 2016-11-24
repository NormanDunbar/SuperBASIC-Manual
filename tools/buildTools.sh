# Compile the tools utilities. These don't come down from GitHub, so 
# they will need recompiling each time a fresh install is done.
#
# You uneed to be in the tools directory to run this build script.
#
#
# Norman Dunbar
# 4th August 2016.

for CPP in `ls *.cpp`
do
    EXE=${CPP%%.cpp}
    g++ -std=gnu++11 -o ${EXE} ${CPP}
    echo ${CPP} has been compiled to ${EXE}
done


