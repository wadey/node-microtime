# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added
- Prebuild support for Windows ARM64 (`win32-arm64`).
- ARM64 (`ubuntu-24.04-arm`, `macos-latest`, `windows-11-arm`) testing in the CI test matrix.
- Weekly CITGM and published prebuild workflow across supported OS, Node.js (including `27-nightly` and `28-nightly`), and architecture targets (`x86`, `x64`, `arm64`).
- `npm pack` and prebuild verification steps in CI test workflows.
- `CHANGELOG.md` documenting project release history.

### Changed
- Replaced `.npmignore` with explicit `files` allowlist in `package.json`.
- Replaced `antonyurchenko/git-release` Docker action with `gh release` CLI in the release workflow.

### Fixed
- Trigger `test-release` workflow automatically after the `Release` workflow completes via `workflow_run`.

## [4.0.1] - 2026-11-11

NOTE: 4.0.0 was skipped due to a Github Actions issue

### Added
- Post-release workflow to verify prebuilds from GitHub Releases.
- Manual `workflow_dispatch` trigger on the release workflow.

### Changed
- **Breaking:** Require Node.js `>= 22.22.2` minimum.
- Updated `node-addon-api` to `^8.9.2`, `node-gyp` to `^13.1.0`, `prebuildify` to `^6.0.1`, `prebuildify-cross` to `^5.1.1`, and `standard` to `^17.1.0`.
- Updated prebuild targets to Node.js `22.22.2` and Electron `35.2.0` (including `almalinux-devtoolset11`, `alpine`, `linux-armv6`, `linux-armv7`, and `linux-arm64-lts`).
- Dropped Android prebuild target and Windows x86 testing on Node.js 24+.
- Updated `cross-env` to `^10.1.0` and `actions/checkout` to v7.

### Fixed
- Fixed GitHub Actions release workflow compatibility with `prebuildify-cross` and removed redundant `linux-arm64` build group.

## [3.1.1] - 2022-08-11

### Added
- Prebuild support for `linux-arm64`.

### Removed
- Removed legacy Travis CI and AppVeyor configuration files.

## [3.1.0] - 2022-06-08

### Added
- Universal macOS (`darwin-x64+arm64`) prebuilds.
- GitHub Actions workflows for testing, smoke builds, and releases.

### Changed
- Updated dependencies (`node-addon-api`, `node-gyp-build`, `prebuildify`, `prebuildify-cross`).

## [3.0.0] - 2019-02-04

### Changed
- **Breaking:** Ported native addon from `nan` to Node-API (`N-API` via `node-addon-api`).
- Switched from `prebuild` / `prebuild-install` to `prebuildify` and `node-gyp-build` so N-API prebuilds are bundled directly in the npm package.
- Improved `ErrnoException` error formatting to preserve C error codes.

## [2.1.9] - 2019-01-26

### Changed
- Updated `nan` to `2.12.x`, `prebuild`, and `prebuild-install`.

## [2.1.8] - 2018-05-15

### Added
- Prebuild and CI support for Node.js 10.

### Changed
- Updated `nan` to `2.10.x`.

## [2.1.7] - 2018-01-02

### Added
- Prebuild and CI support for Node.js 9.

### Changed
- Only test and prebuild for Node.js 4+.
- Updated `clang-format` and `prebuild` dependencies.

## [2.1.6] - 2017-07-05

### Changed
- Switched from `node-pre-gyp` to `prebuild` and `prebuild-install` for prebuilt binaries.
- Added package keywords to `package.json`.

## [2.1.5] - 2017-06-02

### Fixed
- Bundled `node-pre-gyp` in `bundledDependencies` so prebuilt binary installation works on `npm install`.

## [2.1.4] - 2017-06-01

### Added
- Pre-compiled Windows binaries using `node-pre-gyp`.
- CI testing on Node.js 8.

## [2.1.3] - 2017-04-11

### Changed
- Updated `nan` to `2.6.x` and `standard` linter.

## [2.1.2] - 2016-11-17

### Added
- CI testing on Node.js 7.
- Code formatting enforcement with `standard` and `clang-format` (LLVM style).

### Changed
- Updated `nan` to `2.4.x`.

## [2.1.1] - 2016-04-27

### Changed
- Updated `nan` to `2.3.x`.
- Simplified AppVeyor CI configuration.

## [2.1.0] - 2016-04-26

### Added
- CI testing for Node.js 4, 5, and 6 on Linux, macOS, and Windows.

### Changed
- Updated `nan` to `2.2.x`.

## [2.0.0] - 2015-08-09

### Changed
- Upgraded to `nan` `2.0.x` for io.js v3.0.0 / Node.js v4 compatibility.
- Removed `bindings` dependency in favor of direct `nan` usage.

## [1.5.0] - 2015-08-26

### Changed
- Backported `nan` `2.0.x` and io.js v3.0.0 compatibility to the `1.x` release line.

## [1.4.2] - 2015-05-22

### Added
- AppVeyor Windows CI configuration and testing with io.js 1.0 and 2.0.
- `license` field in `package.json`.

## [1.4.1] - 2015-05-05

### Fixed
- Replaced `node::ErrnoException` with `NanThrowError` for broader Node.js/io.js compatibility.

## [1.4.0] - 2015-05-05

### Added
- CI testing on Node.js 0.12 and io.js.

### Changed
- Updated `nan` to `1.8.x`.

## [1.2.0] - 2015-01-14

### Changed
- Updated `nan` to `1.5.x`.

## [1.1.1] - 2015-01-14

### Changed
- Relaxed dependency ranges for `nan` (`1.4.x`) and `bindings` (`1.2.x`).

## [1.1.0] - 2014-12-24

### Added
- Use `GetSystemTimePreciseAsFileTime` on Windows when available for higher resolution timestamps.

### Changed
- Updated `nan` to `1.4.1`.

## [1.0.1] - 2014-08-02

### Changed
- Updated `nan` to `1.3.0` and cleaned up native addon code.

## [1.0.0] - 2014-07-31

### Changed
- Cleaned up module initialization for first stable `1.0.0` release.

## [0.6.0] - 2014-05-15

### Added
- `.npmignore` to exclude `build/` from published packages.
- CI testing on Node.js 0.11.

### Changed
- Updated `nan` to `1.0.0` and `bindings` to `1.2.0`.

## [0.5.1] - 2013-12-11

### Added
- Adopted `nan` for Node.js 0.11.x compatibility.

### Changed
- Require Node.js `>= 0.8.0`.
- Updated `bindings` and `nan` dependencies.

## [0.4.0] - 2013-05-30

### Added
- Initial Windows support (`GetSystemTimeAsFileTime`).
- Travis CI configuration and testing on Node.js 0.9 and 0.10.

## [0.3.2] - 2012-10-03

### Changed
- Updated `bindings` to `1.0.0`.

## [0.3.1] - 2012-03-13

### Fixed
- Removed redundant `preinstall` build script in `package.json`.

## [0.3.0] - 2012-03-13

### Added
- Node.js 0.6.x support.

### Changed
- Switched build system to `node-gyp`.

## [0.1.3] - 2011-02-28

### Added
- Added `test.js` script to estimate clock resolution and documented examples in `README.md`.

## [0.1.2] - 2011-02-28

### Fixed
- Simplified `wscript` so the addon builds on Cygwin.

## [0.1.1] - 2011-02-11

### Added
- Initial release with `now()`, `nowDouble()`, and `nowStruct()`.

[Unreleased]: https://github.com/wadey/node-microtime/compare/v4.0.1...HEAD
[4.0.1]: https://github.com/wadey/node-microtime/compare/v4.0.0...v4.0.1
[4.0.0]: https://github.com/wadey/node-microtime/compare/v3.1.1...v4.0.0
[3.1.1]: https://github.com/wadey/node-microtime/compare/v3.1.0...v3.1.1
[3.1.0]: https://github.com/wadey/node-microtime/compare/v3.0.0...v3.1.0
[3.0.0]: https://github.com/wadey/node-microtime/compare/v2.1.9...v3.0.0
[2.1.9]: https://github.com/wadey/node-microtime/compare/v2.1.8...v2.1.9
[2.1.8]: https://github.com/wadey/node-microtime/compare/v2.1.7...v2.1.8
[2.1.7]: https://github.com/wadey/node-microtime/compare/v2.1.6...v2.1.7
[2.1.6]: https://github.com/wadey/node-microtime/compare/v2.1.5...v2.1.6
[2.1.5]: https://github.com/wadey/node-microtime/compare/v2.1.4...v2.1.5
[2.1.4]: https://github.com/wadey/node-microtime/compare/v2.1.3...v2.1.4
[2.1.3]: https://github.com/wadey/node-microtime/compare/v2.1.2...v2.1.3
[2.1.2]: https://github.com/wadey/node-microtime/compare/v2.1.1...v2.1.2
[2.1.1]: https://github.com/wadey/node-microtime/compare/v2.1.0...v2.1.1
[2.1.0]: https://github.com/wadey/node-microtime/compare/v2.0.0...v2.1.0
[2.0.0]: https://github.com/wadey/node-microtime/compare/v1.4.2...v2.0.0
[1.5.0]: https://github.com/wadey/node-microtime/compare/v1.4.2...v1.5.0
[1.4.2]: https://github.com/wadey/node-microtime/compare/v1.4.1...v1.4.2
[1.4.1]: https://github.com/wadey/node-microtime/compare/v1.4.0...v1.4.1
[1.4.0]: https://github.com/wadey/node-microtime/compare/v1.2.0...v1.4.0
[1.2.0]: https://github.com/wadey/node-microtime/compare/v1.1.1...v1.2.0
[1.1.1]: https://github.com/wadey/node-microtime/compare/v1.1.0...v1.1.1
[1.1.0]: https://github.com/wadey/node-microtime/compare/v1.0.1...v1.1.0
[1.0.1]: https://github.com/wadey/node-microtime/compare/v1.0.0...v1.0.1
[1.0.0]: https://github.com/wadey/node-microtime/compare/v0.6.0...v1.0.0
[0.6.0]: https://github.com/wadey/node-microtime/compare/v0.5.1...v0.6.0
[0.5.1]: https://github.com/wadey/node-microtime/compare/0.4.0...v0.5.1
[0.4.0]: https://github.com/wadey/node-microtime/compare/v0.3.2...0.4.0
[0.3.2]: https://github.com/wadey/node-microtime/compare/0.3.1...v0.3.2
[0.3.1]: https://github.com/wadey/node-microtime/compare/0.3.0...0.3.1
[0.3.0]: https://github.com/wadey/node-microtime/compare/0.1.3...0.3.0
[0.1.3]: https://github.com/wadey/node-microtime/compare/0.1.2...0.1.3
[0.1.2]: https://github.com/wadey/node-microtime/compare/0.1.1...0.1.2
[0.1.1]: https://github.com/wadey/node-microtime/releases/tag/0.1.1
