#unset cmake cache
CMAKE_EXTRA_OPTIONS+=" -UXBUILD_TEST"

for option in $options
do
    case $option in
    test)
        CMAKE_EXTRA_OPTIONS+=" -DXBUILD_TEST=ON"
        if [ $osname == "Linux" ]; then
            CMAKE_EXTRA_OPTIONS+=" -DXENABLE_CODE_COVERAGE=ON"
        fi
        echo "Build with test project"
    ;;
    tcmalloc)
        CMAKE_EXTRA_OPTIONS+=" -DTCMALLOC=ON"
        echo "BUILD TCMALLOC mode"
    ;;
    debug)
        CMAKE_EXTRA_OPTIONS+=" -DCMAKE_BUILD_TYPE=Debug"  # -g
        CBUILD_DIR="cbuild"
    ;;
    release)
        CMAKE_EXTRA_OPTIONS+=" -DCMAKE_BUILD_TYPE=Release"  # -O2(Mac: -O3) -DNDEBUG
        CBUILD_DIR="cbuild_release"
    ;;
    *)
        echo "unknown build option: "$option
        exit
    ;;
    esac
done
