import argparse, os

branches = ['master', '0.1.0']

def main():
    parser = argparse.ArgumentParser(prog = "GitPush", description = "Pushes git changes", epilog = "--message <Commit message>")
    parser.add_argument("-m", "--message")
    args = parser.parse_args()

    for branch in branches:
        os.system(f"git checkout {branch}")
        if branch == "master":
            os.system("git add .")
            os.system("git add lib --force")
        else:
            os.system("git cherry-pick master")
        
        os.system(f"git commit -m {args.message}")
        os.system(f"git push origin {branch}")
        if branch != "master":
            os.system("git checkout master")

if __name__ == "__main__":
    main()