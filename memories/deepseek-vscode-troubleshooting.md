# DeepSeek V4 for Copilot VS Code 兼容性问题

## 问题
- VS Code 更新后（当前 1.126.0），`vizards.deepseek-v4-for-copilot` 扩展可能失效
- 原因是扩展依赖非公开的 Copilot Chat API，VS Code 更新可能破坏兼容性

## 解决方案（按推荐顺序）

### 方案 1：阻止 VS Code 自动更新
```json
"update.mode": "none"
```

### 方案 2：使用 GitHub Copilot LLM Gateway 扩展
- 扩展 ID: `AndrewButson.github-copilot-llm-gateway`
- 配置: Server URL = `https://api.deepseek.com/v1`, Model = `deepseek-chat`
- 有工具调用 JSON 自动修复功能，对 DeepSeek 兼容性更好

### 方案 3：提交 Issue 给扩展作者
- https://github.com/Vizards/deepseek-v4-for-copilot/issues
- 附上 VS Code 版本和错误日志

### 方案 4：回退 VS Code 版本
- 下载旧版: https://code.visualstudio.com/updates

## 记忆同步
- GitHub 仓库: h7tf4jc959-max/Hello-World
- 本地路径: $env:APPDATA\Code\User\globalStorage\github.copilot-chat\memory-tool
- 定时任务: Copilot记忆同步（每30分钟）
- 同步脚本: C:\Users\CCG\sync-copilot-memories.ps1
