import Utils
import ProjectConfig

def Execute():
  ProjectConfig.LoadConfig()
  print('Cleaning...')
  Utils.RemoveDirectory('Binaries')
  Utils.RemoveDirectory('Intermediate')
  Utils.RemoveDirectory('Intermediate')
  Utils.RemoveAllFilesInDirectory('Source', '.dmp')
  Utils.RemoveAllFilesInDirectory('Source', '.vcxproj')
  Utils.RemoveAllFilesInDirectory('Source', '.vcxproj.filters')
  Utils.RemoveFile(ProjectConfig.GetName() + '.sln')
  Utils.RemoveFile(ProjectConfig.GetName() + '.sln.DotSettings.user')
  print('Done')
