cmake -DCMAKE_MAKE_PROGRAM="SEQUENCER PATH GOES HERE\out\ninja\ninja.exe" -G Ninja Multi-Config -B out
cmake --build out --config Debug 
pause
