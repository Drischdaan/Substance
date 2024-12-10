<a name="readme-top"></a>

<div align="center">
  <h3 align="center">Substance</h3>
  <p>Core C++ Library</p>
</div>

<div align="center">

[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]

</div>

## 🗒️ About

Substance is my core library for C++ projects. It is a collection of utilities, data structures, and algorithms. It is intended to be used as a foundation for other projects.

Currently supported platforms and compilers:

- Windows (MSVC)

## 🛣️ Roadmap

The roadmap is a rough outline of the features that are planned to be implemented. The list is not exhaustive and will be updated as the project progresses. The features are not listed in any particular order.

- [ ] Linux support
- [ ] More compiler support (Currently only MSVC is supported)
- [ ] Custom data structures (e.g. Vector, Map, etc.)
- [ ] Custom string implementation
- [ ] Full control over memory allocations

## 🚀 Getting Started

### 📦 Prerequisites

- [Python 3.9 or above](https://www.python.org/downloads/)
- [Visual Studio 2022](https://visualstudio.microsoft.com/downloads/) or [Visual Studio Build Tools 2022](https://visualstudio.microsoft.com/downloads/?q=build+tools) with the following components:
  - Desktop development with C++
  - MSVC v143
  - Windows 11 SDK (10.0.26100.0 or above recommended, not tested with older versions)

### 🛠️ Setting up the workspace

After cloning the repository, run the following commands in the root directory (Choose the appropriate scripts for your OS):

```bash
# Windows
.\CLI.bat setup
```

This command will install the necessary dependencies and tools required to build the project. It will also generate the Visual Studio solution file.

### 🧹 Cleaning the workspace

If you encounter any issues with the build system, you can clean the workspace with the following commands:

```bash
# Windows
.\CLI.bat clean
```

This will remove all build artifacts, intermediate files, manually downloaded dependencies and tools. You need to run the setup script again to restore the workspace to a working state.

## 📜 License

See [LICENSE](./LICENSE) for more information.

## 🫱🏽‍🫲🏽 Contact

[![Github][github]][github-url]
[![Discord][discord]][discord-url]
[![Twitter][twitter]][twitter-url]

<!-- Variables -->

[issues-shield]: https://img.shields.io/github/issues/Drischdaan/Substance.svg?style=for-the-badge
[issues-url]: https://github.com/Drischdaan/Substance/issues
[license-shield]: https://img.shields.io/github/license/Drischdaan/Substance.svg?style=for-the-badge
[license-url]: https://github.com/Drischdaan/Substance/blob/master/LICENSE.txt

<!-- Socials -->

[github]: https://skillicons.dev/icons?i=github
[github-url]: https://github.com/Drischdaan
[discord]: https://skillicons.dev/icons?i=discord
[discord-url]: https://discord.com/users/244115221776433152
[twitter]: https://skillicons.dev/icons?i=twitter
[twitter-url]: https://twitter.com/Drischdaan
