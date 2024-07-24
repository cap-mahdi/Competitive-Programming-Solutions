#!/bin/bash

while true; do
    echo "Enter platform choice"
    echo "1. Codeforces"
    echo "2. LeetCode"
    read platform_choice
    if [ "$platform_choice" == "1" ] || [ "$platform_choice" == "2" ]; then
        break
    fi
done

if [ "$platform_choice" == "1" ]; then
    read -p "Enter contest name or code: " contest_name
    read -p "Enter division number: " div_number

    
    #Entering number of problems solved (must be a positive integer)
    while true; do
        read -p "Enter number of problems solved: " num_problems
        if   [[ "$num_problems" =~ ^[0-9]+$ ]] && [ $num_problems -gt 0 ]; then
            break
        fi
    done

    solved_problems=()
    #reading problem names: each problem name must be in the format [A-Z][1-2]* and must not be a duplicate
    for i in $(seq 1 $num_problems); do
        while true; do
            read -p "Enter problem $i: " problem
            if [[ ! " ${solved_problems[@]} " =~ " ${problem} " ]] && [[ "$problem" =~ ^[A-Z][1-2]*$ ]] && [[  -f "./$problem.cpp" ]]; then
                solved_problems+=($problem)
                break
            fi
            echo "Invalid problem name/ duplicate problem name / file do not exist"
        done
    done
    #echo "Solved problems: ${solved_problems[@]}"
elif [ "$platform_choice" == "2" ]; then
    echo "LeetCode is not supported yet"
    exit 0
fi

contest_folder="codeforces_${contest_name}_div_${div_number}"


files_names=()
#files_names should exits in current directory
for i in $(seq 1 $num_problems); do
    file_name="${solved_problems[$i-1]}.cpp"
    if [ ! -f "./$file_name" ]; then
        echo "Error: File $file_name does not exist"
        exit 1
    fi
    files_names+=($file_name)
done

#check if there is a folder with the same name
if [ -d ~/Desktop/cp-solutions/codeforces/$contest_folder ]; then
    echo "Error: Folder ~/Desktop/cp-solutions/codeforces/$contest_folder already exists"
    exit 1
fi

#check if the main folder exists
if [ ! -d ~/Desktop/cp-solutions/codeforces ]; then
    echo "Error: Folder ~/Desktop/cp-solutions/codeforces does not exist"
    exit 1
fi

#read problem code (it should be a positive integer)
while true; do
    read -p "Enter problem code: " problem_code
    if [[ "$problem_code" =~ ^[0-9]+$ ]]; then
        break
    fi
done

#read problem names
problem_names=()
for i in $(seq 1 $num_problems); do
    read -p "Enter problem name ${solved_problems[$i-1]}: " problem_name
    problem_name=$(echo $problem_name| sed 's/[[:space:]]\+/ /g' | sed 's/^ *//;s/ *$//' | tr ' ' '\n' | awk '{print toupper(substr($0,1,1)) tolower(substr($0,2))}' | tr -d '\n')
    problem_names+=($problem_name)
done


mkdir -p ~/Desktop/cp-solutions/codeforces/$contest_folder
echo "Creating folder: $contest_folder"
for i in $(seq 1 $num_problems); do
    fileName="${problem_code}${solved_problems[$i-1]}-${problem_names[$i-1]}.cpp"
    cp "./${files_names[$i-1]}" ~/Desktop/cp-solutions/codeforces/$contest_folder/$fileName
    #write at the start of each file 
    # /*
    # Problem Link: https://codeforces.com/contest/$contest_name/problem/${solved_problems[$i-1]}
    # Created  By mahdich02 on dd/mm/yyyy
    # */
    problem_link="https://codeforces.com/contest/$problem_code/problem/${solved_problems[$i-1]}"
    sed -i "1i /*\nProblem Link: $problem_link\nCreated By mahdich02 on $( date +"%Y-%m-%d" )\n*/" ~/Desktop/cp-solutions/codeforces/$contest_folder/$fileName


    echo "Copying ${files_names[$i-1]}"
done


# ask user if he wants to push the files to github
while true; do
    read -p "Do you want to push the files to github? (y/n): " push_to_github
    if [ "$push_to_github" == "y" ] || [ "$push_to_github" == "n" ]; then
        break
    fi
done

if [ "$push_to_github" == "n" ]; then
    exit 0
fi
cd ~/Desktop/cp-solutions
git add .
git commit -m "Add $contest_folder"
git push origin main
echo "Files pushed to github"
