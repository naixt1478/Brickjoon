$Sources1 = Get-ChildItem -Path "." -File
foreach ($Source1 in $Sources1)
{
    if($Source1.Extension -eq ".cc" -or $Source1.Extension -eq ".cpp")
    {
        New-Item -Path . -Name $Source1.BaseName -ItemType "Directory"
        New-Item -Path $Source1.BaseName -Name "CMakeLists.txt" -ItemType "file"
        $Path1 = -join($Source1.BaseName,"\CMakeLists.txt")
        $Value3 = -join("boj_",$Source1.BaseName) 
        $s1 = -join("project(",$Value3,")")
        $s2 = -join("add_subdirectory(",$Source1.BaseName,")")
        Add-Content -Path $Path1 -Value "#project name"
        Add-Content -Path $Path1 -Value $s1
        Add-Content -Path ".\CMakeLists.txt" -Value $s2
        Move-Item -Path $Source1 -Destination $Source1.BaseName
        $value1 = "add_executable(baekjoon_"
        $Value2 = -join ($value1, $Source1.BaseName, " ", $Source1.Name, ")")
        Add-Content -Path $Path1 -Value $Value2
    }
}