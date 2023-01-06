- `git add .`
- `git commit -m "..."`
- `git push origin <branch-name>`
- `git checkout rc`
- `git pull`
- `git checkout <branch-name>`
- `git merge --squash remotes/origin/rc`

> Then open a PR to avoid conflicts.

While doing sync from UI, we may get a dialogue box, follow it, it will generate a detached head.
After merging detached head create a new branch from it and then merge the new branch to avoid conflicts.

