from git import Repo
import argparse

branches = ['master', '0.1.0']

repo = Repo(".git")

def main():
    parser = argparse.ArgumentParser(prog = "GitPush", description = "Pushes git changes", epilog = "--message <Commit message>")
    parser.add_argument("-m", "--message")
    args = parser.parse_args()

    for branch in branches:
        #repo.git.checkout(branch)
        diff = repo.git.diff(repo.head.commit.tree)
        if diff == "":
            print(f"Your branch has no changes: {branch}")
            if branch == branches[-1]:
                print("Exitting...")
                return
        
        repo.git.add(A=True)
        repo.git.commit(f"-m {args.message}")
        repo.remotes.origin.push(refspec = f"{branch}:{branch}")
        print(f"Changes pushed to: origin:{branch}")

if __name__ == "__main__":
    main()