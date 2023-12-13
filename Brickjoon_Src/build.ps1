Remove-Item -Path ".\CMakeLists.txt" -Force
New-Item -Path . -Name "CMakeLists.txt" -ItemType "file" -Force
Add-Content -Path ".\CMakeLists.txt" -Value "#project name 
project(brickjoon_source)

"

$Sources1 = Get-ChildItem -Path "." -File
foreach ($Source1 in $Sources1)
{
    if($Source1.Extension -eq ".cc" -or $Source1.Extension -eq ".cpp" -or $Source1.Extension -eq ".c")
    {
        $s1 = -join("add_executable(","baekjoon_",$Source1.BaseName," ",$Source1.Name,")")
        Add-Content -Path ".\CMakeLists.txt" -Value $s1
    }
}