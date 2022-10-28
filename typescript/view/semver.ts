const convert = (semverStr: string) => {
  if (!/[0-9]+\.[0-9]+\.[0-9]+$/.test(semverStr)) {
    console.log('invalid format ', semverStr);
    return null;
  }

  const semverList = semverStr.split('.');
  return semverList;
};

const isSemver = (semver1: string, semver2: string) => {
  const semverList1: any = convert(semver1);
  const semverList2: any = convert(semver2);
  if(!semverList1 || !semverList2) {
    return;
  }

  for (let i = 0; i < semverList1.length; i++) {
    if(+semverList1[i] > +semverList2[i]) {
      console.log("1 greater ", semver1);
      return;
    } else if (+semverList1[i] < +semverList2[i]) {
      console.log('2 greater ', semver2);
      return;
    }
  }

  console.log("equal ", semver1, semver2);
  return;
};

const testList = [
  ['1.2.3', '1.4.5'],
  ['1.1ee2.3', '1.4.5'],
  ['1.12.3', '1.4f.5'],
  ['0.12.3', '1.4.5'],
  ['0.12.3', '1.4.'],
  ['1.4.6', '1.4.6'],
];

for(const test of testList) {
  console.log("test: ", test);
  isSemver(test[0], test[1]);
}