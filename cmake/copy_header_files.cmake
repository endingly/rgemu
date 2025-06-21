# copy header files from src_dir to dest_dir, not including subdirectories
function(copy_header_files src_dir dest_dir)
    find_program(Python_EXECUTABLE python NO_CMAKE_FIND_ROOT_PATH)
    set(Python_ARGS "${CMAKE_SOURCE_DIR}/python/copy_include_dir.py")
    execute_process(
        COMMAND ${Python_EXECUTABLE} ${Python_ARGS} ${src_dir} ${dest_dir}
    )
endfunction()