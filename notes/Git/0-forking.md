# ***Github Collaborations***

[Reference Link](https://www.earthdatascience.org/courses/intro-to-earth-data-science/git-github/github-collaboration/update-github-repositories-with-changes-by-others/)


Head and Base in Git:

- The terms "head" and "base" are used as they normally are in Git. The head is the branch which you are on; that is, the branch with your changes. The base is the branch off which these changes are based. This is similar to the terminology used for git rebase and git merge-base.
For example, if I'm comparing changes I've made on my foo123 branch against the main Git repository, the base branch is the master branch of git/git, and the head branch is the foo123 branch of bk2204/git. I would be proposing merging my changes on my foo123 branch into the main Git master branch if I opened a pull request.




![](https://www.earthdatascience.org/images/earth-analytics/git-version-control/git-fork-clone-flow.png)

- When you fork a repo that is being actively worked on by other people, it is good practice to periodically update your fork with updates. Remember that multiple people may be adding to this repo at any given time.


## Sync Your Forked GitHub Repo Using A Reverse Pull Request

To sync the forked repo with parent/central repo on Github:

- Create a pull request on Github.com to update your fork of the repository from the original repo., and

- Run the `git pull` command in the terminal to update your local clone.


## How To Sync or Update Your Forked Repo Using the Github Website

To update your fork on `Github.com`, go to the forked repo. On this page, create a pull request.

- Click on the `New pull request` in the pull request section. 
- On the new page, choose your fork as `base fork` and the parent/central repo as the `head fork`.
    + `IMPORTANT`: You need to click on the text `compare across forks` to be able to select the base and head forks appropriately.

- Then, click on `Create pull request`.
- On the new page, click on `Create pull request` once more to finish creating the pull request.

![An animated gif showing you how to sync a GitHub repo on GitHub.com. In this case, the user lwasser is updating her fork of the the practise repo from the earthlab-education/practice-git-skillz repo. Note that the fork is the base (the repo being updated). The Earth Lab owned repo is the head. You can also sync individual branches within a repo using this same approach.
](https://www.earthdatascience.org/images/earth-analytics/git-version-control/git-reverse-pr-demo.gif)


- When you create this pull request, you will see what files will be updated in your fork.

- After creating the pull request, you need to `merge the pull request`, so that the changes in your colleague’s repo are merged into your fork. The next section of this page explains how to merge a pull request.

### How to merge a Pull Request:

To merge a pull request:
- Open up the pull request.
- Click the green button at the bottom of the pull request page that says `Merge pull request`.
- Click on the `Confirm merge` button.

Once you have conformed the merge, all of the changes from your colleague’s repo are in your repo. When you return to your fork on GitHub.com, you will see the changes that you have just merged into your fork.

![After creating a pull request, you merge the pull request to apply the changes from the original repository to your fork.
](https://www.earthdatascience.org/images/earth-analytics/git-version-control/github-merge-reverse-pull-request.gif)



* When you update your fork using a reverse pull request on GitHub.com, you then need to update your files locally. The steps to do that are below.



## How to Update Your Local Clone

Once you have synced (i.e. updated) your fork on GitHub.com, you are ready to update your cloned repo on your local computer.

To pull down (i.e. copy) the changes merged into your fork, you can use the Terminal and the git pull command.

To begin:

- On your local computer, navigate to your forked repo directory.
- Once you have changed directories to the forked repo directory, run the command git pull.

```git
$ cd <path-to-repo>/<repo-name>
$ git pull
```

You have now updated your local clone with the updates that you merged into your fork from original GitHub repository.


# Working with Remotes




































