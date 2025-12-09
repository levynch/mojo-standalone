# Chromium Base Library

这是一个实验性项目，旨在从 Chromium 中提取 Mojo 模块，使其能够作为独立的跨平台 IPC 通信库使用。项目包含了 Chromium 的基础库（base）和 Mojo 相关组件。

## 版本信息

- **Chromium Tag**: 143.0.7490.0
- **Chromium Revision**: ba1244a6ca103fa348994c5a6d078dbe4ed96e4b


## 安装步骤

### 1. 获取 depot_tools

首先需要安装 [`depot_tools`](https://commondatastorage.googleapis.com/chrome-infra-docs/flat/depot_tools/docs/html/depot_tools_tutorial.html#_setting_up) 并确保它在你的 PATH 环境变量中。

### 2. 同步依赖

然后在项目根目录执行：

```bash
gclient sync
```

这将自动下载所有必需的第三方依赖和工具链。

### 3. 生成构建文件

使用 GN (Generate Ninja) 生成构建文件：

```bash
# 生成 Debug 构建配置
gn gen out/Debug

# 生成 Release 构建配置
gn gen out/Release --args='is_debug=false'
```

### 4. 编译项目

使用 Ninja 进行编译：

```bash
# 编译 Debug 版本
ninja -C out/Debug mojo_unittests

# 编译 Release 版本
ninja -C out/Release mojo_unittests
```

## 构建配置选项

可以通过 `--args` 参数自定义构建配置：

```bash
# 查看所有可用的构建参数
gn args out/Debug --list

# 自定义构建配置示例
gn gen out/Custom --args='
  is_debug=false
  is_component_build=true
  use_goma=false
'
```

## 运行测试

```bash
# 编译并运行所有测试
ninja -C out/Debug base_unittests
out/Debug/base_unittests

# 运行特定测试
out/Debug/base_unittests --gtest_filter=TestName.*
```



## 更多信息

- [Chromium 构建文档](https://chromium.googlesource.com/chromium/src/+/main/docs/README.md)
- [Windows 构建说明](https://chromium.googlesource.com/chromium/src/+/main/docs/windows_build_instructions.md)
- [GN 参考文档](https://gn.googlesource.com/gn/+/main/docs/reference.md)
- [Ninja 构建系统](https://ninja-build.org/)

