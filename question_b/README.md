## Question B

The goal of this question is to write a software library that accepts 2 version string as input and returns whether one is greater than, equal, or less than the other. As an example: “1.2” is greater than “1.1”. Please provide all test cases you could think of.


## Solution

The question is somewhat vague about what kind of version string the library is expected to support, so we will assume they will be similar in some ways to those outlined in [Semantic Versioning 2.0.0](https://semver.org/).



Here is a list of tests cases that will be interesting to validate:

```
# when MAJOR version is smaller
1   < 2
2   < 12
1.5 < 13
0.9 < 1.1

# When MAJOR version are equal but MINOR version is smaller
1.0  <  1.1
1.9  <  1.10

# When both MAJOR and MINOR versions are equal but PATCH is smaller
0.0.1  <  0.0.2
0.0.2  <  0.0.10

# When versions have pre-releases. Since it is impossible to know the
# meaning of every pre release, the library will order them alphabetically
1.0.0-alpha < 1.0.0
1.0.0       < 1.0.1-alpha
1.0.0-alpha < 1.0.0-alpha.1
1.0.0-alpha < 1.0.0-beta
1.0.0-beta  < 1.0.0-xyz

# When versions have build metadata, it should be ignored
1.0.0+exp.sha51 == 1.0.0+xyz
```
