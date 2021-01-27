<AutoPilot:project xmlns:AutoPilot="com.autoesl.autopilot.project" projectType="C/C++" name="hls-syn-pe" top="testbench_pe">
    <Simulation argv="">
        <SimFlow name="csim" setup="false" optimizeCompile="false" clean="false" ldflags="" mflags=""/>
    </Simulation>
    <files>
        <file name="../../pe_tb.cpp" sc="0" tb="1" cflags=" -I/home/uma/Desktop/graduation_project/finn_hlslib/finn-hlslib  -I/home/uma/Desktop/graduation_project/finn_hlslib/finn-hlslib/tb -std=c++0x  -Wno-unknown-pragmas" csimflags=" -Wno-unknown-pragmas" blackbox="false"/>
        <file name="pe_top.cpp" sc="0" tb="false" cflags="-std=c++0x -I/home/uma/Desktop/graduation_project/finn_hlslib/finn-hlslib -I/home/uma/Desktop/graduation_project/finn_hlslib/finn-hlslib/tb" csimflags="" blackbox="false"/>
    </files>
    <solutions>
        <solution name="sol1" status=""/>
    </solutions>
</AutoPilot:project>

