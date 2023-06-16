# specify the path
PROGRAM_FOLDER="./bin"
BUILD_FOLDER="./build"
DIARY_PATH="./diary.txt"

# build the project
if [ ! -d $BUILD_FOLDER ]; then
    mkdir $BUILD_FOLDER
fi
cd $BUILD_FOLDER
cmake ..
make
cd ..

# a simple demo for the using of 4 commands: pdadd, pdlist, pdshow, pdremove
echo "\033[32m[Running] pdlist\033[0m"
${PROGRAM_FOLDER}"/pdlist" ${DIARY_PATH}
echo "\033[32m[Running] pdadd\033[0m"
${PROGRAM_FOLDER}"/pdadd" ${DIARY_PATH} "2023-04-26" "I finished my oop assignment!"
echo "\033[32m[Running] pdshow\033[0m"
${PROGRAM_FOLDER}"/pdshow" ${DIARY_PATH} "2023-04-26"
echo "\033[32m[Running] pdremove\033[0m"
${PROGRAM_FOLDER}"/pdremove" ${DIARY_PATH} "2023-04-10"
echo "\033[32m[Running] pdlist\033[0m"
${PROGRAM_FOLDER}"/pdlist" ${DIARY_PATH} "2023-02-21" "2023-04-26"