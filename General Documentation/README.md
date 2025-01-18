# Embedded Programming 
This repository contains project codes implemented in C/C++ Programming Language through Arduino Coding, simulation through Autodesk Tinkercad, and Schematic Design using Fritzing.

#### Abbrevation
For naming convention purposes and identification, all documentations will be abbreviated as AEP. 

## Version History
| No. | Date Created/Modified | Author | Remarks|
|---|---|---|---|
| 0.0 | January 18, 2025 | Engr. Bien Carlo Halili | Created repository and added initial contents in README.md |
| 0.1 | January 18, 2025 | Engr. Bien Carlo Halili | Added Project Structure in README.md |
| 0.2 | January 18, 2025 | Engr. Bien Carlo Halili | Added Code Deployment Practices in README.md |

## Setup Guide (Windows OS)
| Tech Stack | Purpose | Steps |
|---|---|---|
| Autodesk Tinkercad | Simulation and Programming | Go to https://www.tinkercad.com/ > Create an account |
| Fritzing | Schematic Design | Go to https://github.com/fritzing/fritzing-app/ > Click Code > Download > Unzip |
| GitHub | Deployment and Documentation | Go to https://github.com/ > Sign Up/Sign In |
| Visual Studio Code | Documentation | Go to https://code.visualstudio.com/ > Download for Windows |
| draw.io | Flowcharting and other General Diagrams | Go to https://app.diagrams.net/ |

## Project Structure
The figure below is a general structure that will be followed throughout the project-making process:

![Alt text](Resources/AEP%20Project%20Structure.drawio.png)

## Code Deployment Practices
### Pre-change (VS Code):
1. Click current branch name.
2. Click "Create new branch from...".
3. Click "origin/main".
4. Name branch with the following format: "aep-[purpose of change]".
### Post-change (VS Code):
1. Navigate to Source Control.
2. Briefly explain the changes.
3. Click Commit.
4. Click Sync Changes.
### Post-change (GitHub UI):
1. Navigate to Pull Requests.
2. Click "New pull request".
3. Ensure that base points to "main".
4. Ensure that compare points to the branch containing changes.
5. Fill Title and Description.
6. Click "Create pull request.
7. Click Merge.
8. Optional: Delete compared branch.
### Cleanup (VS Code):
1. Delete remote branch containing change by typing "git branch -d [branch name]" at terminal.
2. Get latest code by checking out at "main" and typing "git pull" at terminal.
3. Get latest remote branches by typing "git fetch --prune" at terminal.
