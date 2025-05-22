class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience)
    {
        int time = 0;
        int en, ex;
        for (int i = 0;i < energy.size();i++)
        {
            if (initialExperience > experience[i])
                initialExperience += experience[i];
            else
            {
                time += experience[i] + 1 - initialExperience;
                initialExperience = experience[i] + 1;
                initialExperience += experience[i];
            }

            if (initialEnergy > energy[i])
            {
                initialEnergy -= energy[i];
            }
            else
            {
                time += energy[i] + 1 - initialEnergy;
                initialEnergy = energy[i] + 1;
                initialEnergy -= energy[i];
            }
        }
        return time;
    }
};